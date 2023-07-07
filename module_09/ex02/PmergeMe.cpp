#include "PmergeMe.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PmergeMe::PmergeMe() { }

PmergeMe::PmergeMe( const PmergeMe & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PmergeMe::~PmergeMe() { }


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PmergeMe &				PmergeMe::operator=( PmergeMe const & rhs )
{
	if ( this != &rhs )
	{
	}
	return *this;
}

/*
** --------------------------------- DEQUE ----------------------------------
*/

int		PmergeMe::jacobsthal(int n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
}

void		PmergeMe::generateJacobInsertionSequence()
{
	size_t	size;
	size_t	jcobstalIndex;
	int		index;

	size = this->_pend.size();
	index = 3;
	while ((jcobstalIndex = this->jacobsthal(index)) < size - 1)
	{
		this->_jacobSequence.push_back(jcobstalIndex);
		index++;
	}
}

void		PmergeMe::generatPositions()
{
	size_t		val;
	size_t		pos;
	size_t		lastPos;

	if (this->_pend.empty())
		return;
	this->generateJacobInsertionSequence();
	lastPos = 1;
	val = 1;
	std::deque<int>::iterator it = this->_jacobSequence.begin();
	while (it != this->_jacobSequence.end())
	{
		val = *it;
		this->_positions.push_back(val);
		pos = val - 1;
		while (pos > lastPos)
		{
			this->_positions.push_back(pos);
			pos--;
		}
		lastPos = val;
		++it;
	}
	while (val++ < this->_pend.size())
		this->_positions.push_back(val);
}

void		PmergeMe::createListOrder()
{
	std::deque<int>::iterator	it;
	std::deque<int>::iterator	insertionPositionIterator;
	int							valueToInsert;
	int							insertionPosition;
	int							addedCount;

	this->generatPositions();
	addedCount = 0;
	for (it = this->_positions.begin(); it < this->_positions.end(); it++)
	{
		valueToInsert = this->_pend.at(*it - 1);
		insertionPosition = *it + addedCount;
		insertionPositionIterator = std::lower_bound(this->_mainChain.begin(), this->_mainChain.begin() + insertionPosition, valueToInsert);
		this->_mainChain.insert(insertionPositionIterator, valueToInsert);
		addedCount++;
	}
	if (_hasStraggler)
	{
		insertionPositionIterator = std::lower_bound(this->_mainChain.begin(), this->_mainChain.end(), _straggler);
		this->_mainChain.insert(insertionPositionIterator, _straggler);
	}
}

void		PmergeMe::createMainChainAndPend()
{
	size_t	i;

	_mainChain.push_back(this->_pairs.at(0).second);
	i = 0;
	while (i < this->_pairs.size())
	{
		_mainChain.push_back(this->_pairs.at(i).first);
		_pend.push_back(this->_pairs.at(i).second);
		i++;
	}
}


void		PmergeMe::merge(std::deque<std::pair<int, int> >& pairs, int begin, int mid, int end)
{
	int									leftSize = mid - begin + 1;
	int									rightSize = end - mid;
	int									k = begin;
	int									i = 0;
	int									j = 0;
	std::deque<std::pair<int, int> >	leftArray(leftSize);
	std::deque<std::pair<int, int> >	rightArray(rightSize);

	for (int i = 0; i < leftSize; ++i)
		leftArray[i] = pairs[begin + i];
	for (int j = 0; j < rightSize; ++j)
		rightArray[j] = pairs[mid + 1 + j];
	while (i < leftSize && j < rightSize) {
		if (leftArray[i].first <= rightArray[j].first) {
			pairs[k] = leftArray[i];
			++i;
		}
		else {
			pairs[k] = rightArray[j];
			++j;
		}
		++k;
	}
	while (i < leftSize)
	{
		pairs[k] = leftArray[i];
		++i;
		++k;
	}
	while (j < rightSize)
	{
		pairs[k] = rightArray[j];
		++j;
		++k;
	}
}


void	PmergeMe::mergeSort(int begin, int end)
{
	int mid;

	if (begin >= end)
		return;
	mid = begin + (end - begin) / 2;
	mergeSort(begin, mid);
	mergeSort(mid + 1, end);
	merge(_pairs, begin, mid, end);
}


void	PmergeMe::sortPairs() 
{
	for (unsigned int i = 0; i < _pairs.size(); ++i)
	{
		if (_pairs[i].first < _pairs[i].second)
		{
			int tmp = _pairs[i].first;
			_pairs[i].first = _pairs[i].second;
			_pairs[i].second = tmp;
		}
	}
}

void		PmergeMe::createPairs()
{
	int size;
	
	size = _inputSequence.size();
	for (int i = 0; i < size; i += 2)
	{
		int first = _inputSequence[i];
		int second = (i + 1 < size) ? _inputSequence[i + 1] : 0;
		_pairs.push_back(std::make_pair(first, second));
	}
}

void		PmergeMe::inputSequenceIsOdd()
{
	_hasStraggler = _inputSequence.size() % 2 != 0;
	if (_hasStraggler) {
		_straggler = _inputSequence[_inputSequence.size() - 1];
		_inputSequence.pop_back();
	} else {
		_straggler = false;
	}
}

void		PmergeMe::fillDeque( int argc, char **input )
{
	int number;

	for (int i = 1; i < argc; i++) {
		number = std::atoi(input[i]);
		_inputSequence.push_back(number);
	}
}

void		PmergeMe::sortDeque( int argc, char **input )
{
	timeDeq = clock();
	fillDeque(argc, input);
	inputSequenceIsOdd();
	createPairs();
	sortPairs();
  	mergeSort(0, _pairs.size() - 1);
	createMainChainAndPend();	
	createListOrder();
	timeDeq = clock() - timeDeq;
}

/*
** --------------------------------- VECTOR ----------------------------------
*/

int		PmergeMe::jacobsthalVec(int n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	return (jacobsthalVec(n - 1) + 2 * jacobsthalVec(n - 2));
}

void		PmergeMe::generateJacobInsertionSequenceVec()
{
	size_t	size;
	size_t	jcobstalIndex;
	int		index;

	size = this->_pendVec.size();
	index = 3;
	while ((jcobstalIndex = this->jacobsthalVec(index)) < size - 1)
	{
		this->_jacobSequenceVec.push_back(jcobstalIndex);
		index++;
	}
}

void		PmergeMe::generatPositionsVec()
{
	size_t		val;
	size_t		pos;
	size_t		lastPos;

	if (this->_pendVec.empty())
		return;
	this->generateJacobInsertionSequenceVec();
	lastPos = 1;
	val = 1;
	std::vector<int>::iterator it = this->_jacobSequenceVec.begin();
	while (it != this->_jacobSequenceVec.end())
	{
		val = *it;
		this->_positionsVec.push_back(val);
		pos = val - 1;
		while (pos > lastPos)
		{
			this->_positionsVec.push_back(pos);
			pos--;
		}
		lastPos = val;
		++it;
	}
	while (val++ < this->_pendVec.size())
		this->_positionsVec.push_back(val);
}

void		PmergeMe::createListOrderVec()
{
	std::vector<int>::iterator	it;
	std::vector<int>::iterator	insertionPositionIterator;
	int							valueToInsert;

	this->generatPositionsVec();
	for (it = this->_positionsVec.begin(); it < this->_positionsVec.end(); it++)
	{
		valueToInsert = this->_pendVec.at(*it - 1);
		insertionPositionIterator = 
		std::lower_bound(this->_mainChainVec.begin(), this->_mainChainVec.end() , valueToInsert);
		this->_mainChainVec.insert(insertionPositionIterator, valueToInsert);
	}
	if (_hasStragglerVec)
	{
		insertionPositionIterator = 
		std::lower_bound(this->_mainChainVec.begin(), this->_mainChainVec.end(), _stragglerVec);
		this->_mainChainVec.insert(insertionPositionIterator, _stragglerVec);
	}
}

void		PmergeMe::createMainChainAndPendVec()
{
	size_t	i;

	_mainChainVec.push_back(this->_pairsVec.at(0).second);
	i = 0;
	while (i < this->_pairsVec.size())
	{
		_mainChainVec.push_back(this->_pairsVec.at(i).first);
		_pendVec.push_back(this->_pairsVec.at(i).second);
		i++;
	}
}

void		PmergeMe::mergeVec(std::vector<std::pair<int, int> >& pairs, int begin, int mid, int end)
{
	int									leftSize = mid - begin + 1;
	int									rightSize = end - mid;
	int									k = begin;
	int									i = 0;
	int									j = 0;
	std::vector<std::pair<int, int> >	leftArray(leftSize);
	std::vector<std::pair<int, int> >	rightArray(rightSize);

	for (int i = 0; i < leftSize; ++i)
		leftArray[i] = pairs[begin + i];
	for (int j = 0; j < rightSize; ++j)
		rightArray[j] = pairs[mid + 1 + j];
	while (i < leftSize && j < rightSize) {
		if (leftArray[i].first <= rightArray[j].first) {
			pairs[k] = leftArray[i];
			++i;
		}
		else {
			pairs[k] = rightArray[j];
			++j;
		}
		++k;
	}
	while (i < leftSize)
	{
		pairs[k] = leftArray[i];
		++i;
		++k;
	}
	while (j < rightSize)
	{
		pairs[k] = rightArray[j];
		++j;
		++k;
	}
}


void	PmergeMe::mergeSortVec(int begin, int end)
{
	int mid;

	if (begin >= end)
		return;
	mid = begin + (end - begin) / 2;
	mergeSortVec(begin, mid);
	mergeSortVec(mid + 1, end);
	mergeVec(_pairsVec, begin, mid, end);
}


void	PmergeMe::sortPairsVec() 
{
	for (unsigned int i = 0; i < _pairsVec.size(); ++i)
	{
		if (_pairsVec[i].first < _pairsVec[i].second)
		{
			int tmp = _pairsVec[i].first;
			_pairsVec[i].first = _pairsVec[i].second;
			_pairsVec[i].second = tmp;
		}
	}
}

void		PmergeMe::createPairsVec()
{
	int size;
	
	size = _inputSequenceVec.size();
	for (int i = 0; i < size; i += 2)
	{
		int first = _inputSequenceVec[i];
		int second = (i + 1 < size) ? _inputSequenceVec[i + 1] : 0;
		_pairsVec.push_back(std::make_pair(first, second));
	}
}

void		PmergeMe::inputSequenceIsOddVec()
{
	_hasStragglerVec = _inputSequenceVec.size() % 2 != 0;
	if (_hasStragglerVec) {
		_stragglerVec = _inputSequenceVec[_inputSequenceVec.size() - 1];
		_inputSequenceVec.pop_back();
	} else {
		_stragglerVec = false;
	}
}

void		PmergeMe::fillVector( int argc, char **input )
{
	int number;

	for (int i = 1; i < argc; i++) {
		number = std::atoi(input[i]);
		_inputSequenceVec.push_back(number);
	}
}

void		PmergeMe::sortVec( int argc, char **input )
{
	timeVec = clock();
	fillVector(argc, input);
	inputSequenceIsOddVec();
	createPairsVec();
	sortPairsVec();
  	mergeSortVec(0, _pairsVec.size() - 1);
	createMainChainAndPendVec();	
	createListOrderVec();
	timeVec = clock() - timeVec;

}

bool		PmergeMe::isValidInput( char** input )
{
   	for (int i = 1; input[i]; i++)
	{
		int j = 0;
		if (input[i][0] == '+')
			j++;
		for (; input[i][j]; j++)
			if (!isdigit(input[i][j]))
				return false;
	}
	return true;
}

bool		PmergeMe::checkArguments( int argc, char **input )
{
	if (argc < 2)
		return (std::cout << ERROR_ARGC << std::endl, false);
	if (!isValidInput(input))
		return (std::cout << BAD_INPUT << std::endl, false);
	return (true);
}


int			PmergeMe::fjmi_sort( int argc, char **input )
{
	if (!checkArguments(argc, input))
		return (1);
	sortDeque(argc, input);
	sortVec(argc, input);
	printUnsorted(input);;
	printSorted();
	printTimeToProcess();
	return 0;
}

void	PmergeMe::printUnsorted(char **input)
{
	std::cout << "Before:	";
	for (int i = 1; input[i]; i++)
	{
		for (int j = 0; input[i][j]; j++)
		{
			if (input[i][j] !=  '+')
				std::cout << input[i][j];
		}
		std::cout << " ";	
	}
	std::cout << std::endl;
}

void	PmergeMe::printSorted(void)
{
	std::cout << "After:	";
	for (std::deque<int>::iterator it = _mainChain.begin(); it != _mainChain.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void	PmergeMe::printTimeToProcess(void)
{
	std::cout << "Time to process a range of " << std::setw(3)
	<< (this->_inputSequence.size()  + 1)  << " elements with std::deque : "
	<< (float)timeVec * 1000 / CLOCKS_PER_SEC << " us" << std::endl;
	std::cout << "Time to process a range of " << std::setw(3)
	<< (this->_inputSequenceVec.size() + 1)   << " elements with std::vector : "
	<< (float)timeDeq * 1000 / CLOCKS_PER_SEC << " us" << std::endl;
}

/* ************************************************************************** */