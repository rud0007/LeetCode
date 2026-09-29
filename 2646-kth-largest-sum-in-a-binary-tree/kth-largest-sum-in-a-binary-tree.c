/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void merge(long long arr[], int left, int mid, int right) {
    long long temp[100000];

    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {

        // Descending order
        if (arr[i] > arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];
}

void mergeSort(long long arr[], int left, int right) {

    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}

long long kthLargestLevelSum(struct TreeNode* root, int k) {

    struct TreeNode* queue[100000];
    long long sum[100000];

    int front = 0, rear = 0;
    int levels = 0;

    queue[rear++] = root;

    while (front < rear) {

        int size = rear - front;
        long long total = 0;

        for (int i = 0; i < size; i++) {

            struct TreeNode* node = queue[front++];

            total += node->val;

            if (node->left)
                queue[rear++] = node->left;

            if (node->right)
                queue[rear++] = node->right;
        }

        sum[levels++] = total;
    }

    if (k > levels)
        return -1;

    // Merge Sort in descending order
    mergeSort(sum, 0, levels - 1);

    return sum[k - 1];
}