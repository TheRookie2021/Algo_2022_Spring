#include <iostream>
using namespace std;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
/*
    1. 進入 build_heapify
        - 找到 mid
        - 由mid 往 0 不斷的呼叫 min_heapify
    2. min_heapify:
        - 找到目標節點下可能的子節點index
        - 判斷是否存在
        - 若存在則比較是否"最小子節點小於目標節點"
        - 若存在"最小子節點小於目標節點"，則交換兩者，並以該點為目標呼叫min_heapify:

*/
void min_heapify(int *arr, int i, int top)
{
    // i: parent, L: left child, R: right child
    int L = i * 2 + 1, R = i * 2 + 2;
    int min;// index of min value of the parent and childs

    // if lchild exist, and if lchild is smaller than min
    if(L<=top && arr[L]<arr[i]){
        min = L;
    }else{
        min = i;
    }
    // if rchild exist, and if rchild is smaller than min
    if(R<=top && arr[R]<arr[min]){
        min = R;
    }
    //if min is not the parent, swap the values and continue recursion(top-down)
    if(min!=i){
        swap(&(arr[min]), &(arr[i]));
        min_heapify(arr, min, top);
    }
    
}

void build_heapify(int *arr, int top)
{
    // bottom-up checking the child
    for (int i = top / 2; i > -1; i--)
    {
        min_heapify(arr, i, top);
    }
}

void heap_sort(int *arr, int top)
{
    // passing copy of arr (do not change the value)
    int temp[top];
    for (int i = 0; i < top; i++)
        temp[i] = arr[i];
    for (int i = top, counter = 0; i > -1;)
    {
        arr[counter++] = temp[0];
        temp[0] = temp[i--];
        // top down heapify
        for (int j = 0; j <= i;)
        {
            if ((j * 2) + 2 <= i) // parent with 2 children
            {
                if (temp[j * 2 + 1] < temp[j * 2 + 2]) // left child
                {
                    if ((temp)[j] > (temp)[j * 2 + 1])
                    {
                        swap(&(temp)[j], &(temp)[j * 2 + 1]);
                        j = j * 2 + 1;
                    }
                    else
                        break;
                }
                else if ((temp)[j * 2 + 1] >= (temp)[j * 2 + 2]) // right child
                {
                    if ((temp)[j] > (temp)[j * 2 + 2])
                    {
                        swap(&(temp)[j], &(temp)[j * 2 + 2]);
                        j = j * 2 + 2;
                    }
                    else
                        break;
                }
                else
                    break;
            }
            else if ((j * 2) + 1 <= i) // parent with 1 children
            {
                if ((temp)[j] > (temp)[j * 2 + 1])
                {
                    swap(&(temp)[j], &(temp)[j * 2 + 1]);
                    j = j * 2 + 1;
                }
                else
                    break;
            }
            else // else: leaf nodes, skip.`
                break;
        }
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    build_heapify(arr, N - 1);
    //heap_sort(arr,N);
    // int flag=2;
    for (int i = 0; i < N; i++){
        // if(i==flag-1){
        //     cout<<endl;
        //     flag*=2;
        // }
        cout << arr[i] << " ";
    }

    return 0;
}
