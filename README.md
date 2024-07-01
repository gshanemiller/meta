# Description

**Input**: An array of strings city, and an array of unsigned integers population in 1:1 correspondence such that city[i] has population population[i]. Let T be the sum of entries in population. 

**API**: A class accepting city, population as constructor const references equipped with a public method void print()

**Output**: When print() is invoked it shoud print exactly one city indexed by i with probability probability city[i]/T.

**Non-functional Performance**: print will be call millions of times. It should be performant.

**Example**: city={NY,SF,LA}; population={20,10,30} e.g. LA popuation is 30. print() should write 'LA' to stdout 1/2 of the time since 30/T = 30/60 = 1/2.

**Assumption**: The input city, population arrays must descending sorted so highest population city at index 0. This can be worked around by a quicksort O(n log n) on both arrays together.

# Sample output
```
./build
./run
generating 10000 data points ...
city={LA, NY, SF}, population={30,20,10}

LA expected about 50 pct or about 5000
5022
NY expected about 33 pct or about 3333
3331
SF expected about 17 pct or about 1667
1647
```

# Algorithm Performance
Storage is O(n):
  * O(n) in size of city array
  * O(n) in size of population array
  * O(n) in helper array for proability weight

Runtime is:
  * Worst case O(n)
  * Average case is O(n) with but with a constant k on n k~1/3.

# Algorithm Discussion
**One Time Work**: A helper array is created such the ith entry covers a range of the unit interval equal to `city[i]/T`. So given `city={"LA", "NY", "SF"}, population={30,20,10}` the code computes `d_weight={0.5, 0.83, 1.0]`. 

In this way

    * half the unit interval `[0, 0.5]` corresponds to city 0,
    * `[0.5, .83]` or `.83333-0.5=0.3333` or 1/3rd for city one
    * etc.
    * remainder for the last city.

When `print()` is run, a uniform random number is drawn from `[0,1]` and is used to see which index it's less than in `d_weight`
