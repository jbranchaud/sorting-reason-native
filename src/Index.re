let unsorted_list = [7, 3, 6, 1, 9, 2, 4, 5, 8];
let expected_list = [1, 2, 3, 4, 5, 6, 7, 8, 9];

let sorted_list = InsertionSort.sort(unsorted_list);

Invariant.expect(sorted_list == expected_list);

let sorted_list_2 = SelectionSort.sort(unsorted_list);

Invariant.expect(sorted_list_2 == expected_list);