int binarySearch(int[] a, int x){
  int low = 0;
  int high = a.length - 1;
  int mid;

  while(low <= high){
    mid = (low + high) / 2;
    if (a[mid] < x){
      low = mid + 1;
    }else if (a[mid] > x) {
      high = mid - 1;
    }else{
      return mid;
    }
  }
  return -1; //Error
}

/* recursive version */
public static int bsearch(int[] i, int left, int right, int findMe){
  if (left> right){
    return FAILURE;
  }
  int mid = (left + right)/2;

  if(findMe == i[mid]){
    return mid;
  }else if (findMe < i[mid]) {
    return bsearch(i, left, mid + 1, findMe)
  }else{
    return bsearch(i, mid-1, right, findMe);
  }
}

public static int bsearch(int[] i, int findMe){
  bsearch(i, 0, i.length-1, findMe);
}