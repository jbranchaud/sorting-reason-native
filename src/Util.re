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

/* swap two items in an array */
let array_swap = (items: array('a), i, j) => {
  let temp = items[i];
  items[i] = items[j];
  items[j] = temp;
};