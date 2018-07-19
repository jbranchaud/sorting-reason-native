/*
 Selection Sort
 https://en.wikipedia.org/wiki/Selection_sort

 /* a[0] to a[n-1] is the array to sort */
 int i,j;
 int n;

 /* advance the position through the entire array */
 /*   (could do j < n-1 because single element is also min element) */
 for (j = 0; j < n-1; j++)
 {
     /* find the min element in the unsorted a[j .. n-1] */

     /* assume the min is the first element */
     int iMin = j;
     /* test against elements after j to find the smallest */
     for (i = j+1; i < n; i++)
     {
         /* if this element is less, then it is the new minimum */
         if (a[i] < a[iMin])
         {
             /* found new minimum; remember its index */
             iMin = i;
         }
     }

     if (iMin != j)
     {
         swap(a[j], a[iMin]);
     }
 }
 */

let sort = (items: list(int)) : list(int) => {
  let j = ref(0);
  let len = List.length(items);
  let swappable_items = ref(items);

  while (j^ < len - 1) {
    let iMin = ref(j^);
    let i = ref(j^ + 1);

    while (i^ < len) {
      let iValue = List.nth(swappable_items^, i^);
      let iMinValue = List.nth(swappable_items^, iMin^);
      if (iValue < iMinValue) {
        iMin := i^;
      };

      i := i^ + 1;
    };

    if (iMin^ != j^) {
      swappable_items := Util.swap(swappable_items^, j^, iMin^);
    };

    j := j^ + 1;
  };

  swappable_items^;
};