/*Name : Syed Mohammad Abbas
Class : B.Tech 2nd Year 
Faculty No. 20COB228
Class Roll No. : 27
Enrollment : GK0703 */

#include <stdio.h>
int bs(int arr[], int select, int lw, int hg)
{
    if (hg <= lw) {
    	if (select > arr[lw])
			return  (lw + 1);
		return lw;
	}


    int mid = lw + (hg - lw)/2;

    if(select == arr[mid])
        return mid+1;

    if(select > arr[mid])
        return bs(arr, select, mid+1, hg);
    return bs(arr, select, lw, mid-1);
}

int main() {

	int arr[100], n, i, j, k,l, n1, n2, strt, c, l2,left[100],right[100], size, li, ri,  t,s , ind = 0, tabl, tab[20], pos, l1,a, ins, tabpt[10];

	cout<<("Enter number of elements:");
	cin>>("%d",&n);

	/*Generating the array */
	cout("Enter array elements:\n");
	srand(time(0));
	for (i=0;i<n;i++) {
		scanf("%d",&arr[i]);
	}
	cout<<("\nThe array elements generated are \n");
	for(i=0;i<n;i++)
	{
		cout<<("%d\t",arr[i]);
	}
	cout<<("\n\nMerge Sort Begins\n");

	for (i = 1; i<n; i = i*2) 
	{ /* it will start merging for 1 element array and will be increamented then*/

		c= n/(i*2) + 1;
		ind = 0;
		strt = 0;

		while (c > 0) {
			n1 = i;
			if (strt + 2 * i >= n)
				n2 = n - strt - i;
			else
				n2 = i;

		s = strt;
		for ( t = 0; t< n1; t++) {
			left[t] = arr[s];
			s++;
		}
		for ( t = 0; t< n2; t++) {
			if (s > n)  break;
			right[t] = arr[s];
			s++;
		}
		if (s > n)  break;
		li = 0; // 1st subarray-initial index
   		ri = 0; // 2nd subarray-initial index

   		if (n2 != 0 && n1/n2 >= 3) // 2nd array is smaller
		{
			tabl = n1/n2;               // number of tabs required
			k = 0;
			l = 0;
			size = n1/tabl;                // tab size
			while (k<n1) {
				tab[l] = arr[k];
				k = k + size;
				l++;
			}

			for (l1 = 0; l1<n2;l1++) 
			{


				for (a=0;a<tabl;a++){
					if (right[l1] > tab[a] && right[l1] <= tab[a+1])  // finding tab in which the element is to be inserted
						ins = a;
				}
				if (ins +1 >= tabl) break;
				for (l2 = 0; l2<size ;l2++) {
					tabpt[l2] = arr[ins * size + l2];

				}
				pos = bs(tabpt, right[l1], 0, size-1); // finding pos in selected tab by  function binary serch

				pos = ins * size + pos ;
				l2 = n;
				while(l2 > pos){
					 arr[l2] = arr[l2-1 ];  // shifting elements
            		l2--;
				}

				arr[l2] =right[l1];

			}
		}
	else {  // checking if both array are equal or not

    	while (li < n1 && ri < n2) {
        	if (left[li] <= right[ri]) {
            	arr[ind] = left[li];
            	li++;
        	}
        	else {
            	arr[ind] = right[ri];
            	ri++;
        	}
        	ind++;
    	}

    /* remaining elements of  1st subarray to be copied  */
    	while (li < n1) {
        	arr[ind] = left[li];
        	li++;
        	ind++;
    	}

    /* remaining elements of 2nd subarray to be copied  */
    	while (ri < n2) {
        	arr[ind] = right[ri];
        	ri++;
        	ind++;
    	}

}
		cout<<("\n");
		for (k = 0; k<n;k++)
		cout<<("%d\t", arr[k]);
		strt = strt + i*2;
		c --;
	   
	}

	}
	cout<<("\n\nThe final sorted array elements are:\n");
	for(k=0;k<n;k++)
	  cout<<("%d\t",arr[k]);
	return 0;

}