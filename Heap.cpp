/* binary heap */

#include<iostream>
#include<climits>
using namespace std;

class BinaryHeap{
	public:
	//pointer to point the array elements
		int * hArr;
	//maximum posible size of array
		int mSize;
	//current size of the array
		int cSize;

	//constructor
		BinaryHeap(int mSize){
			hArr=new int[mSize];
			this->mSize=mSize;
			cSize=0;
		};
 
	//parent node: Arr[(i-1)/2]
		int parent(int i){
			return (i-1)/2;
		}

	//left node: Arr[(2*i)+1]
		int left(int i){
			return (i*2)+1;
		}

	//right node: Arr[(i*2)+2]
		int right(int i){
			return (i*2)+2;
		}

	//function swap
		void swap(int * a, int * b){
			int temp= *a;
			*a = *b;
			*b=temp;
		}

	//function getMin
		int getMin(){
		//get the 1st element
			return hArr[0];
			//cout<< hArr[0];
		}
	
	//function insert
		void insert(int value){
		//base case: check if the heap overflows
			if(cSize==mSize){
				cout<<"SORRY, overflowed..."<<endl;
				return;
			}
		//insert the new value
			cSize++;
			int i=cSize-1;
			hArr[i]=value;
		//check if it violets the property-if it does then swap
			while(i!=0 and hArr[parent(i)] > hArr[i]){
				swap(&hArr[i],&hArr[parent(i)]);
				i=parent(i);
			}
		}

	//function display
		int display(){
			for(int i=0;i<cSize;i++){
				cout<<hArr[i]<<"|";
			}
			cout<<endl;
		}

	//function extractMin
		int extractMin(){
		//call the function getMin and store it
			int root=getMin();
		//base case for empty heap
			if(cSize<=0){
				cout<<"nothing exists..."<<endl;
			}
		//base case for heap with one element
			else if(cSize==1)
				return hArr[0];
		//copy the last element to the root
			else
				hArr[0]=hArr[cSize-1];
		//decrease the cSize
				cSize--;
		//call MinHeapify on root
				MinHeapify(0);
		//return the min
				return getMin();
		}

	//function decreaseKey
		void decreaseKey(int value,int i){
		//replace any element with new value
			hArr[i]=value;
		//if parent is greater than that elemet then swap
			while(i!=0 and hArr[parent(i)]>hArr[i]){
				swap(&hArr[i],&hArr[parent(i)]);
				i=parent(i);
			
			}
		}

	//function deleteAt
		void deletAt(int i){

		//decrease the value to INT_MIN using decreaseKey
			decreaseKey(INT_MIN,i);
			//display();
		//use extractMin
			extractMin();
		}

	//function MinHeapify
		void MinHeapify(int i){
		//l=left(i)
			int l=left(i);
		//r=right(i)
			int r=right(i);
			int smallest=i;
		//compare l and r
			if(l<cSize and hArr[l]<hArr[i])
		//replace with smallest
				smallest=l;
			if(r<cSize and hArr[r]<hArr[smallest])
				smallest=r;
			if(smallest!=i){
				swap(&hArr[i], &hArr[smallest]);
		//call MinHeapify at the replaced child
				MinHeapify(smallest);
			}
		}
};
			

	//drive the program
int main(){
	BinaryHeap bh1(20);
    for(int i = 10; i >0 ; i--){
        cout << "Inserting " << i << endl;
        bh1.insert(i);
		cout<<endl;
		
        bh1.display();
    }
	cout<<endl;
	//bh1.getMin();
    bh1.extractMin();
    bh1.display();
    bh1.deletAt(3);
    bh1.display();
    //cout << endl;
}
