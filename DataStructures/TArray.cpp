/*
* Sorting TArray using predicate. By default sorting occurs automatically if the < operator is defined in the element type the TArray holds, otherwise a predicate should be define
*/

/* [Example for sorting an TArray<FOnlineSessionSearchResult> based on ping] */

TArray<FOnlineSessionSearchResult> SortedSearchResults = SearchResults; // Assume this has different search results
SortedSearchResults.Sort(IsLowerPing); // Predicate function passed by reference

/* The predicate would be the following */
bool static IsLowerPing(const FOnlineSessionSearchResult& ResultA, const FOnlineSessionSearchResult& ResultB)
{
  return ResultA.PingInMs < ResultB.PingInMs; 
};


/*
* Removing elements from a huge TArray while iterating it without shrinking the array for performance
*/

/* [Example for choosing an actor based on chance, and removing the chosen actor] */

for (int i = 0; i < OutActors.Num(); i++)
{
	if (FMath::RandRange(1, 100) > ChanceOfChoosingLootSpawnActor) // ChanceOfChoosingLootSpawnActor has a value from 1 to 100, so higher the value, the lesser the chance of choosing this actor to remove
	{
		/*
		 * For optimized removal, we remove element by swapping the last element to the index we want to remove and the array is not shrunk. It is shrunk at last, since shrinking everytime an element is removed is unnecessary in this case and waste of CPU time.
		 * Check out the following blog for more info : https://www.unrealengine.com/en-US/blog/optimizing-tarray-usage-for-performance
		 */
		OutActors.RemoveAtSwap(i, 1, false);
		i--;
  }
}
OutActors.Shrink(); // Finally shrink the array






