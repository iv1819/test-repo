#include <iostream>
#include <iomanip>
using namespace std;

class Nguoi{
	protected:
		string ht;
		int ns;
		//nguvy
	public:
		void nhap(){
			cout<<"Nhap ho ten: ";getline(cin,ht);
			cout<<"Nhap nam sinh: ";cin>>ns;
			cin.ignore();
		}
		void xuat(){
			cout<<left<<setw(20)<<ht<<setw(10)<<ns;
		}
};
class MonHoc{
	protected:
		string tm;
		float dcc, dkt, dt;
	public:
		void nhap(){
			cout<<"Nhap ten mon hoc: ";getline(cin,tm);
			cout<<"Nhap diem chuyen can: ";cin>>dcc;
			cout<<"Nhap diem kiem tra: ";cin>>dkt;
			cout<<"Nhap diem thi: ";cin>>dt;
			cin.ignore();
		}
		void xuat(){
			cout<<setw(15)<<tm<<setw(10)<<dcc<<setw(10)<<dkt<<setw(10)<<dt;
		}
};
class SinhVien: public MonHoc, public Nguoi{
	protected:
		string msv;
		float dtb;
	public:
		void nhap(){
			Nguoi::nhap();
			MonHoc::nhap();
			cout<<"Nhap ma sinh vien: ";getline(cin,msv);
		}
		void xuat(){
			Nguoi::xuat();
			MonHoc::xuat();
			dtb = (dcc + dt + dkt)/3;
			cout<<setw(15)<<msv<<setw(10)<<dtb<<endl;
		}
		float getDtb(){
			return dtb;
		}
		float getDcc(){
			return dcc;
		}
		float getDkt(){
			return dkt;
		}
		float getDt(){
			return dt;
		}
		string getHt(){
			return ht;
		}
		string getMsv(){
			return msv;
		}
		
};
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void title(){
	cout<<"--------------------------DANH SACH SINH VIEN----------------------------\n";
	cout<<left<<setw(20)<<"Ho ten"<<setw(10)<<"Nam sinh"<<setw(15)<<"Ten mon"<<setw(10)<<"Diem CCan"<<setw(10)<<"Diem Ktra"<<setw(10)<<"Diem thi"<<setw(15)<<"Ma sinh vien"<<setw(10)<<"Diem TBinh"<<endl;
}
int main(int argc, char** argv) {
	int n,i,j,count=0,vt;
	float td[n],tdg,max = td[0];
	do{
		cout<<"Co bao nhieu sinh vien: ";cin>>n;
	}while(n<=0);
	cin.ignore();
	SinhVien *sv = new SinhVien[n];
	for(i=0;i<n;i++){
		cout<<"\nNhap vao thong tin sinh vien thu "<<i+1<<endl;
		sv[i].nhap();
		td[i] = sv[i].getDcc() + sv[i].getDkt() + sv[i].getDt();
	}
	title();
	for(i=0;i<n;i++){
		sv[i].xuat();
	}
	SinhVien svg;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(sv[i].getDtb()<sv[j].getDtb()){
				svg = sv[i];
				sv[i] = sv[j];
				sv[j] = svg;
				tdg = td[i];
				td[i] = td[j];
				td[j] = tdg;
			}
		}
	}
	cout<<"\nSau khi sap xep theo thu tu giam dan cua diem trung binh\n"<<endl;
	title();
	for(i=0;i<n;i++){
		sv[i].xuat();
	}
	bool once;
	cout<<"\nDanh sach sinh vien bi cam thi:"<<endl;
	for(i=0;i<n;i++){
		if(sv[i].getDcc()<5||sv[i].getDkt()==0){
			if(once == false){
				title();
				once = true;
			}
			sv[i].xuat();
			count++;
		}
	}
	if(count ==0){
		cout<<"Khong co sinh vien nao bi cam thi"<<endl;
	}
	string tk;
	cout<<"\nNhap ma sinh vien hoac ho ten cua sinh vien can tim: ";getline(cin,tk);
	count =0;
	for(i=0;i<n;i++){
		if(sv[i].getHt().compare(tk)==0||sv[i].getMsv().compare(tk)==0){
			title();
			sv[i].xuat();
			count++;
		}
	}
	if(count ==0){
		cout<<"Khong co sinh vien nao co thong tin tren"<<endl;
	}
	for(i=0;i<n;i++){
		if(max<td[i]){
			max = td[i];
			vt=i;	
		}
	}
	cout<<"\nSinh vien co tong diem cao nhat\n"<<endl;
	title();
	sv[vt].xuat();
	delete[] sv;
	if(sv != NULL){
		delete sv;
		sv = NULL;
	}
	return 0;
}
