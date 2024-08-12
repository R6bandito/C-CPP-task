/*���һ������ͼ�ε�ϵͳ��ϵͳ����һ������ Shape���������������� Circle �� Rectangle��
ÿ����״����һ����������ĺ��� getArea()��
ʹ�ö�̬����ʵ�ֲ�ͬ��״��������㣬����дһ�����Գ�����ʾ��̬�ԡ�*/

#include <iostream>
#include <math.h>
using namespace std;

//����
class shape     
{
    public:
    shape():S(0.0){
        cout<<"���๹�캯������"<<endl;
    }
    virtual void getArea() = 0;    //���麯�������ֶ�̬��
    virtual ~shape(){
        cout<<"������������"<<endl;
    }  //����������
    virtual void disPlay() const = 0;
    virtual void inputData() = 0;

    protected:
    double S;

};

//���������� Circle 
class Circle : public shape     
{
    private:
    int radius;
    const double PI = 3.1415;

    public:
    Circle():radius(0){
        cout<<"Circle���캯������"<<endl;
    }    //���캯��������ʼ����
    ~Circle(){
        cout<<"Circle��������"<<endl;
    }
    void inputData() override;     //�û�����뾶
    void getArea() override;    //�������
    void disPlay() const override {
        cout<<"Բ�����Ϊ:"<<S<<endl;
    }
};

//���������� Rectangle
class Rectangle : public shape
{
    private:
    int length;
    int width;

    public:
    Rectangle():length(0),width(0){
        cout<<"Rectangle���캯������"<<endl;
    }
    ~Rectangle(){
        cout<<"Rectangle��������"<<endl;
    }
    void inputData() override;   //�û����볤���
    void getArea() override;    //�������
    void disPlay() const override{
        cout<<"�������Ϊ:"<<S<<endl;
    }
};

void Function(shape* sp)
{
    sp->inputData();
    sp->getArea();
    sp->disPlay();
}

int main(int argc,const char* argv[])
{
    //�ڶ������ٶ���
    Rectangle* re = new Rectangle;
    Circle* ce = new Circle;
    Function(re);
    Function(ce);
    //�ֶ��ͷŶ���
    delete re;  
    delete ce;
    return 0;
}


inline void Circle::inputData()
{
    cout<<"������뾶��������"<<endl;
    cin>>radius;
}

inline void Circle::getArea()
{
    S = PI * pow(radius,2);
}

inline void Rectangle::inputData()
{
    cout<<"�����볤���"<<endl;
    cin>>length>>width;
}

inline void Rectangle::getArea()
{
    S = length*width;
}