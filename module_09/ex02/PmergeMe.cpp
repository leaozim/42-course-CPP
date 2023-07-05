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

int PmergeMe::binarySearch(std::deque<int> array, int target, int begin, int end)
{
 	int mid;

	while (begin <= end)
	{
		mid = begin + (end - begin) / 2;
		if (target == array.at(mid))
			return (mid);

		if (target > array.at(mid))
			begin = mid + 1;
		else
			end = mid - 1;
	}
	if (target > array.at(mid))
		return (mid + 1);
	else
		return (mid);
}


// void PmergeMe::insertToMainChain()
// {
// 	std::deque<int>::iterator it;
// 	int target;
// 	int endPos;
// 	int addedCount;
// 	int pos;

// 	this->generatPositions();
// 	addedCount = 0;
//  	for (it = this->positions.begin(); it < this->positions.end(); it++)
// 	{
// 		target = this->pend.at(*it - 1);
// 		endPos = *it + addedCount;
// 		pos = this->binarySearch(this->mainChain, target, 0, endPos);
// 		this->mainChain.insert(this->mainChain.begin() + pos, target);
// 		addedCount++;
// 	}
// 	if (this->inputdeque.size() % 2 != 0)
// 	{
// 		target = this->inputdeque.at(this->inputdeque.size() - 1);
// 		pos = this->binarySearch(this->mainChain, target, 0, this->mainChain.size() - 1);
// 		this->mainChain.insert(this->mainChain.begin() + pos, target);
// 	}
// }

void PmergeMe::insertToMainChain()
{
    std::deque<int>::iterator it;
    int target;
    int endPos;
    int addedCount;
    int pos;

    this->generatPositions();
    addedCount = 0;
    for (it = this->positions.begin(); it != this->positions.end(); it++)
    {
        target = this->pend.at(*it - 1);
        endPos = *it + addedCount;
        pos = this->binarySearch(this->mainChain, target, 0, endPos);
        this->mainChain.insert(this->mainChain.begin() + pos, target);
        addedCount++;
    }
    target = this->pend.front();
    pos = this->binarySearch(this->mainChain, target, 0, this->mainChain.size() - 1);
    this->mainChain.insert(this->mainChain.begin() + pos, target);
    if (this->inputdeque.size() % 2 != 0)
    {
        target = this->inputdeque.at(this->inputdeque.size() - 1);
        pos = this->binarySearch(this->mainChain, target, 0, this->mainChain.size() - 1);
        this->mainChain.insert(this->mainChain.begin() + pos, target);
    }
}

void PmergeMe::createMainChainAndPend(std::deque<int>& pend, const std::deque<std::deque<int> >& pairsOrder)
{
    std::deque<std::deque<int> >::const_iterator it;

    mainChain.push_back(pairsOrder.front().front()); 
    pend.push_back(pairsOrder.front().back());

    for (it = pairsOrder.begin() + 1; it != pairsOrder.end(); ++it)
    {
        mainChain.push_back(std::max((*it).front(), (*it).back()));
        pend.push_back(std::min((*it).front(), (*it).back()));
    }
}


void merge(std::deque<std::deque<int> >& pairsOrder, int begin, int mid, int end)
{
    int leftSize = mid - begin + 1;
    int rightSize = end - mid;
    int k = begin;
 	int i = 0;
    int j = 0;
    std::deque<std::deque<int> > leftArray(leftSize);
    std::deque<std::deque<int> > rightArray(rightSize);

    for (int i = 0; i < leftSize; ++i)
        leftArray[i] = pairsOrder[begin + i];
    for (int j = 0; j < rightSize; ++j)
        rightArray[j] = pairsOrder[mid + 1 + j];
    while (i < leftSize && j < rightSize) {
        if (leftArray[i].front() <= rightArray[j].front()) {
            pairsOrder[k] = leftArray[i];
            ++i;
        }
        else {
            pairsOrder[k] = rightArray[j];
            ++j;
        }
        ++k;
    }
    while (i < leftSize)
    {
        pairsOrder[k] = leftArray[i];
        ++i;
        ++k;
    }
    while (j < rightSize)
    {
        pairsOrder[k] = rightArray[j];
        ++j;
        ++k;
    }
}


void mergeSort(std::deque<std::deque<int> >& pairsOrder, int begin, int end)
{
	int mid;

	if (begin >= end)
		return;
	mid = begin + (end - begin) / 2;
	mergeSort(pairsOrder, begin, mid);
	mergeSort(pairsOrder, mid + 1, end);
	merge(pairsOrder, begin, mid, end);
}


void	PmergeMe::sortPairs(std::deque<std::deque<int> >& pairs) 
{
	std::deque<std::deque<int> >::iterator	it;
	int										firstElement;
	int										secondElement;

	for (it = pairs.begin(); it != pairs.end(); ++it) {
		std::deque<int>& pair = *it;
		firstElement = pair.front();
		secondElement = pair.back();
		if (firstElement < secondElement) {
			std::swap(firstElement, secondElement);
			pair.front() = firstElement;
			pair.back() = secondElement;
		}
	}
}


void PmergeMe::create_pairs(const std::deque<int>& inputdeque) {
  	std::deque<int> 					tempdeque;
	std::deque<int> 					newdeque;
	int								    value;

	for (std::deque<int>::const_iterator it = inputdeque.begin(); it != inputdeque.end(); ++it)
	{
		value = *it;
		if (tempdeque.size() == 1) { 
			tempdeque.push_back(value); 
			pairs.push_back(tempdeque);
			tempdeque.clear(); 
		}
		else if (pairs.size() * 2 == pairs.size() - 1) { 
			newdeque.push_back(*it);
			pairs.push_back(newdeque);   
		}
		else 
			tempdeque.push_back(value);
	}
}

bool		PmergeMe::checkArguments( int argc, char **input )
{
	if (argc < 2)
		return (std::cout << ERROR_ARGC << std::endl, false);
	if (!isValidInput(input))
		return (std::cout << BAD_INPUT << std::endl, false);
	return (true);
}
// int			PmergeMe::fjmi_sort( int argc, char **input )
// {
// 	if (!checkArguments(argc, input))
// 		return (1);
//     for (int i = 1; i < argc; i++) {
//         int number = std::atoi(input[i]);
//         inputdeque.push_back(number);
//     }

//     // bool hasStraggler = inputdeque.size() % 2 != 0;
//     // int straggler = 0;
//     // if (hasStraggler) {
//     //     straggler = inputdeque.back();
//     //     inputdeque.pop_back();
//     // }

//     // Exibindo a dequea A e o valor do straggler
 
// 	create_pairs(inputdeque);

//     // Exibindo os pares
//     std::deque<std::deque<int> >::const_iterator it;
//     for (it = pairs.begin(); it != pairs.end(); ++it) {
//         std::cout << "Pair: ";
//         std::deque<int>::const_iterator inner_it;
//         for (inner_it = it->begin(); inner_it != it->end(); ++inner_it) 
//             std::cout << *inner_it << " ";
//         std::cout << std::endl;
//     }
// 	 sortPairs(pairs);
//     for (it = pairs.begin(); it != pairs.end(); ++it) {
//         std::cout << "Pair ordenado: ";
//         std::deque<int>::const_iterator inner_it;
//         for (inner_it = it->begin(); inner_it != it->end(); ++inner_it) 
//             std::cout << *inner_it << " ";
//         std::cout << std::endl;
//     }


//     // Imprimir o resultado
//   	mergeSort(pairs, 0, pairs.size() - 1);
// 	std::deque<std::deque<int> >::const_iterator outerIt;
//     std::deque<int>::const_iterator innerIt;

//     for (outerIt = pairs.begin(); outerIt != pairs.end(); ++outerIt)
//     {
//         for (innerIt = outerIt->begin(); innerIt != outerIt->end(); ++innerIt)
//             std::cout << *innerIt << " ";
//         std::cout << std::endl;
//     }

//     createMainChainAndPend(pend, pairs);

// 	std::cout << "mainChain: ";
//     std::deque<int>::const_iterator mainIt;
//     for (mainIt = mainChain.begin(); mainIt != mainChain.end(); ++mainIt)
//         std::cout << *mainIt << " ";
//     std::cout << std::endl;

//     std::cout << "pend: ";
//     std::deque<int>::const_iterator pendIt;
//     for (pendIt = pend.begin(); pendIt != pend.end(); ++pendIt)
//         std::cout << *pendIt << " ";
//     std::cout << std::endl;


//     insertToMainChain();
//     std::cout << "mainChain: "<< std::endl;
//     for (mainIt = mainChain.begin(); mainIt != mainChain.end(); ++mainIt)
//         std::cout << *mainIt << " ";
//     std::cout << std::endl;
//     return 0;
// }
int			PmergeMe::fjmi_sort( int argc, char **input )
{
	if (!checkArguments(argc, input))
		return (1);
	for (int i = 1; i < argc; i++) {
		int number = std::atoi(input[i]);
		inputdeque.push_back(number);
	}
	create_pairs(inputdeque);
	sortPairs(pairs);
  	mergeSort(pairs, 0, pairs.size() - 1);
	// sort_by_larger_value(pairs);
		// std::deque<std::deque><int> >::const_iterator outerIt;
    // std::deque<int>::const_iterator innerIt;
	// std::cout <<   "insetriomn " << std::endl;
    // for (outerIt = pairs.begin(); outerIt != pairs.end(); ++outerIt)
    // {
    //     for (innerIt = outerIt->begin(); innerIt != outerIt->end(); ++innerIt)
    //         std::cout << *innerIt << " ";
    //     std::cout << std::endl;
    // }

	createMainChainAndPend(pend, pairs);
	insertToMainChain();
	std::cout << "mainChain: "<< std::endl;
	std::deque<int>::const_iterator mainIt;
	for (mainIt = mainChain.begin(); mainIt != mainChain.end(); ++mainIt)
		std::cout << *mainIt << " ";
	std::cout << std::endl;
	return 0;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/
// 2 53 
// 7 8 
// 11 46 
// 27 100

/* ************************************************************************** */