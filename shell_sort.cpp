#include<iostream>
using namespace std;

class shell_sort{
	
	private:
		double *array;
		int n;
	
	public:
		void insert();
		void sort();
		void display();
};

void shell_sort :: insert(){
	cout<<"Enter array size:\n";
	cin>>n;
	array=new double[n];
	cout<<"now enter elements"<<"\n";
	for(int i=0;i<n;i++){
		cin>>array[i];
	}
}

void shell_sort :: sort(){
	int i,j,inc=3;
	double temp;
	while(inc>0){
		for(i=0;i<n;i++){
			j=i;
			temp=array[i];
			while((j>=inc)&&array[j-inc]>temp){
				array[j]=array[j-inc];
				j=j-inc;
			}
			array[j]=temp;
		}
		
		if(inc/2!=0){
			inc=inc/2;
		}
		else if (inc==1){
			inc=0;
		}
		else{
			inc=1;
		}
	}
}

void shell_sort :: display(){
	cout<<"the sorted numbers are"<<"\n";
	for(int i=0;i<n;i++){
		cout<<array[i]<<"\t";
		cout<<endl;
	}
}

int main(){
	shell_sort shs;
	shs.insert();
	shs.sort();
	shs.display();
	
	return 0;
}
