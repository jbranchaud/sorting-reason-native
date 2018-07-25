let unsorted_list = [7, 3, 6, 1, 9, 2, 4, 5, 8];
let expected_list = [1, 2, 3, 4, 5, 6, 7, 8, 9];

let InsertionSort.List(sorted_list) =
  InsertionSort.sort(InsertionSort.List(unsorted_list));

Invariant.expect(sorted_list == expected_list);

let InsertionSort.Array(sorted_array) =
  InsertionSort.sort(InsertionSort.Array(Array.of_list(unsorted_list)));

Invariant.expect(Array.of_list(expected_list) == sorted_array);

let sorted_list_2 = SelectionSort.sort(unsorted_list);

Invariant.expect(sorted_list_2 == expected_list);

let sorted_list_3 = RecursiveInsertionSort.sort(unsorted_list);
Invariant.expect(sorted_list_3 == expected_list);