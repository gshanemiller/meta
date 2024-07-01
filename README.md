# description

**Input**: An array of strings city, and an array of unsigned integers population in 1:1 correspondence such that city[i] has population population[i]. Let T be the sum of entries in population. 

**API**: A class accepting city, population as constructor const references equipped with a public method void print()

**Output**: When print() is invoked it shoud print exactly one city indexed by i with probability probability city[i]/T.

**Non-functional Performance**: print will be call millions of times. It should be performant.

**Example**: city={NY,SF,LA}; population={20,10,30} e.g. LA popuation is 30. print() should write 'LA' to stdout 1/2th of the time since 30/T = 30/60 = 1/2.

**Assumption**: The input city, population arrays must descending sorted so highest population city at index 0. This can be worked around by a quicksort O(n log n) on both arrays together.

# build code
./build

# run code
./run

# sample output
generating 10000 data points ...
LA expected about 50 pct or about 5000
5089
NY expected about 33 pct or about 3333
3239
SF expected about 17 pct or about 1667
1672
