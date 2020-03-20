/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int find(int* array, int x, int size){
    if(size == 0) return 0;
    for(int i = 0; i < size; i++){
        if(*(array+i) == x){
            *(array+i) = -999;
            return 1;
        }
    }
    return 0;
}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    *returnSize = 0;
    int tmpSize;
    
    if(nums1Size > nums2Size) tmpSize = nums1Size;
    else tmpSize = nums2Size;
    
    int* result = malloc(tmpSize * sizeof(int));
    int index = 0;
    
    if(nums1Size < nums2Size){
        for(int j = 0; j < nums1Size; j++){
            if(find(nums2, *(nums1+j), nums2Size) == 1){ 
                *(result+index) = *(nums1+j);
                index ++;
            }
        }
    }
    else {
        for(int j = 0; j < nums2Size; j++){
            if(find(nums1, *(nums2+j), nums1Size) == 1){ 
                *(result+index) = *(nums2+j);
                index ++;
            }
        }
    }
    
    *returnSize = index;
    return result;
}
