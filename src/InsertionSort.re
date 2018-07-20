/*
 Insertion Sort
 https://en.wikipedia.org/wiki/Insertion_sort

 i ← 1
 while i < length(A)
     j ← i
     while j > 0 and A[j-1] > A[j]
         swap A[j] and A[j-1]
         j ← j - 1
     end while
     i ← i + 1
 end while
 */

let inner_condition = (items, j) =>
  switch (j > 0) {
  | false => false
  | true =>
    let item1 = List.nth(items, j - 1);
    let item2 = List.nth(items, j);
    item1 > item2;
  };

let array_inner_condition = (items: array(int), j) =>
  switch (j > 0) {
  | false => false
  | true =>
    let item1 = items[j - 1];
    let item2 = items[j];
    item1 > item2;
  };

let sort_list = (items: list(int)) : list(int) => {
  let swappable_items = ref(items);
  let len = List.length(items);
  let i = ref(1);
  while (i^ < len) {
    let j = ref(i^);
    while (inner_condition(swappable_items^, j^)) {
      swappable_items := Util.swap(swappable_items^, j^, j^ - 1);
      j := j^ - 1;
    };
    i := i^ + 1;
  };
  swappable_items^;
};

let sort_array = (items: array(int)) : array(int) => {
  let len = Array.length(items);
  let i = ref(1);

  while (i^ < len) {
    let j = ref(i^);
    while (array_inner_condition(items, j^)) {
      Util.array_swap(items, j^, j^ - 1);
      j := j^ - 1;
    };
    i := i^ + 1;
  };

  items;
};

type sortable =
  | Array(array(int))
  | List(list(int));

let sort = (items: sortable) : sortable =>
  switch (items) {
  | Array(array_of_items) => Array(sort_array(array_of_items))
  | List(list_of_items) => List(sort_list(list_of_items))
  };