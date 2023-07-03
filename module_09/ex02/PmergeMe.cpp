#include "PmergeMe.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe( const PmergeMe & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PmergeMe::~PmergeMe()
{
}


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

// std::ostream &			operator<<( std::ostream & o, PmergeMe const & i )
// {
// 	//o << "Value = " << i.getValue();
// 	return o;
// }


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

void createMainChainAndPend(std::list<int>& mainChain, std::list<int>& pend, const std::list<std::list<int> >& pairsOrder)
{
    mainChain.push_back(pairsOrder.front().back());

    std::list<std::list<int> >::const_iterator it;
    for (it = pairsOrder.begin(); it != pairsOrder.end(); ++it)
    {
        mainChain.push_back((*it).front());
        pend.push_back((*it).back());
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


void merge(std::list<std::list<int> >& pairsOrder, int begin, int mid, int end)
{
    std::list<std::list<int> > leftArray;
    std::list<std::list<int> >::iterator leftArrayIt = pairsOrder.begin();
    std::advance(leftArrayIt, begin);
    for (int i = begin; i <= mid; ++i)
    {
        leftArray.push_back(*leftArrayIt);
        ++leftArrayIt;
    }

    std::list<std::list<int> > rightArray;
    std::list<std::list<int> >::iterator rightArrayIt = pairsOrder.begin();
    std::advance(rightArrayIt, mid + 1);
    for (int i = mid + 1; i <= end; ++i)
    {
        rightArray.push_back(*rightArrayIt);
        ++rightArrayIt;
    }

    std::list<std::list<int> >::iterator mergedArrayIt = pairsOrder.begin();
    std::advance(mergedArrayIt, begin);

    while (!leftArray.empty() && !rightArray.empty())
    {
        if (leftArray.front().front() <= rightArray.front().front())
        {
            *mergedArrayIt = leftArray.front();
            leftArray.pop_front();
        }
        else
        {
            *mergedArrayIt = rightArray.front();
            rightArray.pop_front();
        }
        ++mergedArrayIt;
    }

    while (!leftArray.empty())
    {
        *mergedArrayIt = leftArray.front();
        leftArray.pop_front();
        ++mergedArrayIt;
    }

    while (!rightArray.empty())
    {
        *mergedArrayIt = rightArray.front();
        rightArray.pop_front();
        ++mergedArrayIt;
    }
}

void mergeSort(std::list<std::list<int> >& pairsOrder, int begin, int end)
{
    if (begin >= end)
        return;

    int mid = begin + (end - begin) / 2;
    mergeSort(pairsOrder, begin, mid);
    mergeSort(pairsOrder, mid + 1, end);
    merge(pairsOrder, begin, mid, end);
}


std::list<std::list<int> >	sortPairs(std::list<std::list<int> >& pairs) 
{
    std::list<std::list<int> >::iterator	it;
	int										firstElement;
    int										secondElement;

	for (it = pairs.begin(); it != pairs.end(); ++it) {
		std::list<int>& pair = *it;
        firstElement = pair.front();
        secondElement = pair.back();
        if (firstElement < secondElement) {
            std::swap(firstElement, secondElement);
            pair.front() = firstElement;
            pair.back() = secondElement;
        }
    }
    return (pairs);
}


std::list<std::list<int> > create_pairs(const std::list<int>& inputList) {
	std::list<std::list<int> > 		pairsList; 
  	std::list<int> 					tempList;
	std::list<int> 					newList;
	int								value;

	for (std::list<int>::const_iterator it = inputList.begin(); it != inputList.end(); ++it)
	{
		value = *it;
		if (tempList.size() == 1) { 
			tempList.push_back(value); 
			pairsList.push_back(tempList);
			tempList.clear(); 
		}
		else if (pairsList.size() * 2 == pairsList.size() - 1) { 
			newList.push_back(*it);
			pairsList.push_back(newList);   
		}
		else { 
			tempList.push_back(value);
		}
	}
  return pairsList;
}
int			PmergeMe::fjmi_sort( int argc, char **input )
{
	if (!checkArguments(argc, input))
		return (1);

    std::list<int> inputList;

    // Começando a partir do índice 1 para pular o nome do programa (argv[0])
    for (int i = 1; i < argc; i++) {
        int number = std::atoi(input[i]);
        inputList.push_back(number);
    }

    bool hasStraggler = inputList.size() % 2 != 0;
    int straggler = 0;

    if (hasStraggler) {
        straggler = inputList.back();
        inputList.pop_back();
    }

    // Exibindo a lista A e o valor do straggler
    std::cout << "Lista A: ";
    for (std::list<int>::iterator it = inputList.begin(); it != inputList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Straggler: " << straggler << std::endl;
	std::list<std::list<int> > pairs = create_pairs(inputList);

    // Exibindo os pares
    std::list<std::list<int> >::const_iterator it;
    for (it = pairs.begin(); it != pairs.end(); ++it) {
        std::cout << "Pair: ";
        std::list<int>::const_iterator inner_it;
        for (inner_it = it->begin(); inner_it != it->end(); ++inner_it) {
            std::cout << *inner_it << " ";
        }
        std::cout << std::endl;
    }
	std::list<std::list<int> > pairsOrder = sortPairs(pairs);
    for (it = pairsOrder.begin(); it != pairsOrder.end(); ++it) {
        std::cout << "Pair ordenado: ";
        std::list<int>::const_iterator inner_it;
        for (inner_it = it->begin(); inner_it != it->end(); ++inner_it) {
            std::cout << *inner_it << " ";
        }
        std::cout << std::endl;
    }


    // Imprimir o resultado
  	mergeSort(pairsOrder, 0, pairsOrder.size() - 1);
	std::list<std::list<int> >::const_iterator outerIt;
    std::list<int>::const_iterator innerIt;

    for (outerIt = pairsOrder.begin(); outerIt != pairsOrder.end(); ++outerIt)
    {
        for (innerIt = outerIt->begin(); innerIt != outerIt->end(); ++innerIt)
        {
            std::cout << *innerIt << " ";
        }
        std::cout << std::endl;
    }
    createMainChainAndPend(mainChain, pend, pairsOrder);

	std::cout << "mainChain: ";
    std::list<int>::const_iterator mainIt;
    for (mainIt = mainChain.begin(); mainIt != mainChain.end(); ++mainIt)
    {
        std::cout << *mainIt << " ";
    }
    std::cout << std::endl;

    // Imprimir pend
    std::cout << "pend: ";
    std::list<int>::const_iterator pendIt;
    for (pendIt = pend.begin(); pendIt != pend.end(); ++pendIt)
    {
        std::cout << *pendIt << " ";
    }
    std::cout << std::endl;

    return 0;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */