/*
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

/* swap two items in a list */
let swap = (items, i, j) => {
  /* find the values that need to be swapped */
  let i_item = List.nth(items, i);
  let j_item = List.nth(items, j);

  /* partial application of mapi to create swapper function */
  let swapper =
    List.mapi((index, item) =>
      switch (index) {
      | x when x == i => j_item
      | x when x == j => i_item
      | _ => item
      }
    );

  /* swap the items in the items list */
  swapper(items);
};

let inner_condition = (items, j) =>
  switch (j > 0) {
  | false => false
  | true =>
    let item1 = List.nth(items, j - 1);
    let item2 = List.nth(items, j);
    item1 > item2;
  };

let sort = (items: list(int)) : list(int) => {
  let swappable_items = ref(items);
  let len = List.length(items);
  let i = ref(1);
  while (i^ < len) {
    let j = ref(i^);
    while (inner_condition(swappable_items^, j^)) {
      swappable_items := swap(swappable_items^, j^, j^ - 1);
      j := j^ - 1;
    };
    i := i^ + 1;
  };
  swappable_items^;
};