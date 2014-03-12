#include<iostream>
using namespace std;


//=======================
//Zeller Class Difinition
//Variavle y: year user input
//Variable m: month 
//Variable d:date
//Variable l: the year is leap or not
//=======================

class Zeller{
	int i,j,k;
	
public:
	Zeller():i(0),j(0),k(0){};

	int leap(int y);
	int zeller(int y,int m,int d);


};

///leap function

int Zeller::leap(int y){
  	int l;
  	if( !( y % 100 == 0 )&&( y % 4 == 0) ){
    	l=1; //the year is leap.
  	}else{
    	l=0; //the year is ordinary.
  	}

  	//test
  	//cout<<"lのあたい"<<l<<endl;
  	//
	return l;
}




///zeller function

int Zeller::zeller(int y,int m,int d){
	int h;

	if(m<=2){
		m += 12;
		y -= 1;
	}

  	h = ((d + (26*(m+1))/10)+ y%100 + ((y%100)/4) +(5*(y/100))+((y/100)/4) ) % 7;

  		//test
  		//cout<<"hのあたいだおin zeller"<<h<<endl;
  		//

  	return h;
}



//=========================
//Calender Class Difinition
//=========================

class Calendar{
	int i,j,k;
public:
	Calendar():i(0),j(0),k(0){};
	void printer(int h,int y,int m,int l);
};

void Calendar::printer(int h,int y,int m,int l){ 
	///(0-6,sut-fri)>>(1-7,sun-sut)
	if(h == 0){
		h = 7;
	}
	

	//test
	//cout<<"hの値in printer"<<h<<endl;
	//


	///daymax difinition
	
	switch(m){
	 	case 2:
	 		if(l == 1){ 
	 			//daymax is 29
    			j=29;

	 		}else if(l==0){
	 			//daymax is 28
	 			j=28;
		    	
	 		}
	 	break;

	 	case 4:
	 	case 6:
	 	case 9:
	 	case 11:
			//daymax is 30
	 		j=30;
    	break;

	 	case 1:
	 	case 3:
	 	case 5:
	 	case 7:
	 	case 8:
	 	case 10:
	 	case 12:
	 		//daymax is 31
	 		j=31;	
		    
    	break;
	}	
	


	//print heading
	cout<<"============================"<<endl;
	printf("month:%d\n",m);
	cout<<" Sun Mon Tue Wed Thu Fri Sat"<<endl;
	cout<<"----------------------------"<<endl;
	

	///print calendar
	int k; //repeat counter.

	for(k=1;k<h;k++){
		printf("    ");//four spaces
	}

	for(k=1;k<=j;k++){
		printf("%4d",k);

		
		h++;
		
		if(h%7==1){
			printf("\n");
		}

	}



}

////////////////////////////////////////////
//main function  ///////////////////////////
////////////////////////////////////////////

////test 18:20
int main(void){

	int y,m,d;
	int l,h;


	Zeller zell;
	Calendar cal1;

	cout<<"type the year"<<endl;
	
	cin>>y;

	l = zell.leap(y);

	m=1;
	d=1;

	for(m=1;m<=12;m++){

		h = zell.zeller(y,m,d);

		cal1.printer(h,y,m,l);
		cout<<endl;
	}

	return 0;


};


