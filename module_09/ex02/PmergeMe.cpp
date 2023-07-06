#include "PmergeMe.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PmergeMe::PmergeMe()  { }

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
** --------------------------------- METHODS ----------------------------------
*/





void PmergeMe::generateJacobInsertionSequence()
{
	size_t	size;
	size_t	jcobstalIndex;
	int		index;

	size = this->pend.size();
	index = 3;
	while ((jcobstalIndex = this->jacobsthal(index)) < size - 1)
	{
		this->jacobSequence.push_back(jcobstalIndex);
		index++;
	}
}

int PmergeMe::jacobsthal(int n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
}

void PmergeMe::generatPositions()
{
	size_t val;
	size_t pos;
	size_t lastPos;

	if (this->pend.empty())
		return;
	this->generateJacobInsertionSequence();
	lastPos = 1;
	val = 1;
	std::deque<int>::iterator it = this->jacobSequence.begin();
	while (it != this->jacobSequence.end())
	{
		val = *it;
		this->positions.push_back(val);
		pos = val - 1;
		while (pos > lastPos)
		{
			this->positions.push_back(pos);
			pos--;
		}
		lastPos = val;
		++it;
	}
	while (val++ < this->pend.size())
		this->positions.push_back(val);
}


void PmergeMe::createMainChainAndPend()
{
	size_t i;

	mainChain.push_back(this->pairs.at(0).second);
	i = 0;
	while (i < this->pairs.size())
	{
		mainChain.push_back(this->pairs.at(i).first);
		pend.push_back(this->pairs.at(i).second);
		i++;
	}
}

void merge(std::deque<std::pair<int, int> >& pairs, int begin, int mid, int end)
{
    int leftSize = mid - begin + 1;
    int rightSize = end - mid;
    int k = begin;
    int i = 0;
    int j = 0;
    std::deque<std::pair<int, int> > leftArray(leftSize);
    std::deque<std::pair<int, int> > rightArray(rightSize);

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


void mergeSort(std::deque<std::pair<int, int> >& pairsOrder, int begin, int end)
{
	int mid;

	if (begin >= end)
		return;
	mid = begin + (end - begin) / 2;
	mergeSort(pairsOrder, begin, mid);
	mergeSort(pairsOrder, mid + 1, end);
	merge(pairsOrder, begin, mid, end);
}


void	PmergeMe::sortPairs() 
{
	for (unsigned int i = 0; i < pairs.size(); ++i)
    {
        if (pairs[i].first < pairs[i].second)
        {
            int tmp = pairs[i].first;
            pairs[i].first = pairs[i].second;
            pairs[i].second = tmp;
        }
    }
}


void PmergeMe::createPairs()
{
    int size = inputdeque.size();
    for (int i = 0; i < size; i += 2)
    {
        int first = inputdeque[i];
        int second = (i + 1 < size) ? inputdeque[i + 1] : 0;
        pairs.push_back(std::make_pair(first, second));
    }
}

bool PmergeMe::isValidInput( char** input )
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

void PmergeMe::createListOrder()
{
    std::deque<int>::iterator it;
	std::deque<int>::iterator insertion_point;
    int target;
    int endPos;
    int addedCount;

    this->generatPositions();
    addedCount = 0;
    for (it = this->positions.begin(); it < this->positions.end(); it++)
    {
        target = this->pend.at(*it - 1);
        endPos = *it + addedCount;
        insertion_point = std::lower_bound(this->mainChain.begin(), this->mainChain.begin() + endPos, target);
        this->mainChain.insert(insertion_point, target);
        addedCount++;
    }
    if (hasStraggler)
    {
        target = this->inputdeque.at(this->inputdeque.size() - 1);
        insertion_point = std::lower_bound(this->mainChain.begin(), this->mainChain.end(), straggler);
        this->mainChain.insert(insertion_point, straggler);
    }
}


int			PmergeMe::fjmi_sort( int argc, char **input )
{
	if (!checkArguments(argc, input))
		return (1);
	for (int i = 1; i < argc; i++) {
		int number = std::atoi(input[i]);
		inputdeque.push_back(number);
	}
		hasStraggler = inputdeque.size() % 2 != 0;

		if (hasStraggler) {
			straggler = inputdeque[inputdeque.size() - 1];
			inputdeque.pop_back();
		} else {
			straggler = false;
		}
	createPairs();
	sortPairs();
  	mergeSort(pairs, 0, pairs.size() - 1);
	    for (std::deque<std::pair<int, int> >::const_iterator it = pairs.begin(); it != pairs.end(); ++it) {
        std::cout << "Pair: " << (*it).first << " " << (*it).second << std::endl;
    }
	createMainChainAndPend();	
	createListOrder();
	for (std::deque<int>::iterator it = mainChain.begin(); it != mainChain.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	return 0;
}


/* ************************************************************************** */