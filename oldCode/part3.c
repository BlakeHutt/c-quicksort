int pivot, i, k;
    pivot = left;
    i = left+1;
    k = right;

    while(i<=k && a[i]<=a[pivot]){
        i++;
        while(i<=k && a[k]>=a[pivot]){
            k--;
        }   
        if(i<k){
            int swapVal = a[i];
            a[i] = a[k];
            a[k] = swapVal;
            i++, k--;
        } //else i++;
    } 
    if(a[k]<a[pivot]){
        int swapPiv = a[k];
        a[k] = a[pivot];
        a[pivot] = swapPiv;
        printf("kval: %d\n a[k]val: %d\n", k, k); 
        return k; // new pivot
        }

