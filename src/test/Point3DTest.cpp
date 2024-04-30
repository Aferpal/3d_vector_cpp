#include"../basicClasses/Point.h"
#include<iostream>
#include<string>

struct AssertionData{
	bool assertionValue;
	std::string errorMessage;
	AssertionData(const bool val, const std::string& str){assertionValue=val; errorMessage=str;}
};

AssertionData returnsExpectedValuesOnGetterFunctions(Point3D* ptr_point3d){
	if(ptr_point3d){ delete ptr_point3d;}
	const float EXPECTED_X_VALUE=1;
	const float EXPECTED_Y_VALUE=2;
	const float EXPECTED_Z_VALUE=3;
	ptr_point3d= new Point3D(1, 2, 3);
	bool res= ( ptr_point3d->getX()==EXPECTED_X_VALUE && ptr_point3d->getY()==EXPECTED_Y_VALUE && ptr_point3d->getZ()==EXPECTED_Z_VALUE );
	return AssertionData(res, std::string("Error on getter function on class Point3D: \nExpected: "+std::string(1, char((int)EXPECTED_X_VALUE-'0'))+", "+std::string(1, char((int)EXPECTED_Y_VALUE-'0'))+", "+std::string(1, char((int)EXPECTED_Z_VALUE-'0'))+"\nActual: "+std::string(1, char((int)ptr_point3d->getX()-'0'))+", "+std::string(1, char((int)ptr_point3d->getY()-'0'))+", "+std::string(1, char((int)ptr_point3d->getZ()-'0'))));
}

AssertionData setsXYZValues(Point3D* ptr_point3d){
	if(ptr_point3d){ delete ptr_point3d; }
	const float EXPECTED_FINAL_X=2;
	const float EXPECTED_FINAL_Y=3;
	const float EXPECTED_FINAL_Z=1;
	ptr_point3d = new Point3D(1, 2, 3);
	ptr_point3d->setX(EXPECTED_FINAL_X);
	ptr_point3d->setY(EXPECTED_FINAL_Y);
	ptr_point3d->setZ(EXPECTED_FINAL_Z);
	bool res= ( ptr_point3d->getX()==EXPECTED_FINAL_X && ptr_point3d->getY()==EXPECTED_FINAL_Y && ptr_point3d->getZ()==EXPECTED_FINAL_Z );
	return AssertionData(res, std::string("Error on getter function on class Point3D: \nExpected: "+std::string(1, char((int)EXPECTED_FINAL_X-'0'))+", "+std::string(1, char((int)EXPECTED_FINAL_Y-'0'))+", "+std::string(1, char((int)EXPECTED_FINAL_Z-'0'))+"\nActual: "+std::string(1, char((int)ptr_point3d->getX()-'0'))+", "+std::string(1, char((int)ptr_point3d->getY()-'0'))+", "+std::string(1, char((int)ptr_point3d->getZ()-'0'))));
}

AssertionData isEqualToOtherObjectWithSameValues(Point3D* ptr_point3d){
	if(ptr_point3d){delete ptr_point3d;}
	ptr_point3d=new Point3D(1, 2, 3);
	Point3D otherPoint(1, 2, 3);
	return AssertionData(*ptr_point3d == otherPoint, "Error on == operator, equal objects return false");
}


int main(){
	int passedTests=0;
	int triedTests=0;
	Point3D* testerPoint=nullptr;
	AssertionData test1= returnsExpectedValuesOnGetterFunctions(testerPoint);
	triedTests++;
	if(test1.assertionValue){
		std::cout<<"Test 1: acknowledged and passed\n";
		passedTests++;
	}else{
		std::cout<<"Error on test 1: "+test1.errorMessage<<'\n';	
	}
	AssertionData test2 = setsXYZValues(testerPoint);
	triedTests++;
	if(test2.assertionValue){
		std::cout<<"Test 2: acknowledged and passed\n";
		passedTests++;
	}else{
		std::cout<<"Error on test 2: "+test2.errorMessage<<'\n';
	}
	AssertionData test3 = isEqualToOtherObjectWithSameValues(testerPoint);
	triedTests++;
	if(test3.assertionValue){
		std::cout<<"Test 3: acknowledged and passed\n";
		passedTests++;
	}else{
		std::cout<<"Error on test 3: "+test3.errorMessage<<'\n';
	}
	std::cout<<"Tests attempted: "<<triedTests<<"\nTest Successfully passed: "<<passedTests<<"\nFailed tests: "<<triedTests-passedTests<<"\n";
	if(testerPoint){std::cout<<"\n...\n...\nFreeing memory and resources\n...\n...\n";delete testerPoint;}
	return 0;
}
