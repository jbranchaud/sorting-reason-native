let rec insert_item = (items: list(int), item: int) =>
  switch (items) {
  | [] => [item]
  | [head, ...rest] when item < head => [item, head, ...rest]
  | [head, ...rest] when item > head =>
    let sorted_rest = insert_item(rest, item);
    [head, ...sorted_rest];
  };

let rec sort = items : list(int) =>
  switch (items) {
  | [] => []
  | [head, ...rest] => insert_item(sort(rest), head)
  };