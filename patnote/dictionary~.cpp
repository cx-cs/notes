#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Word{
	private:
		string word;
		string type;
		string definition;
	public:
		void getters(string wor,string typ,string def){
			word=wor;
			type=typ;
			definition=def;
		}
		void printDefinition(){cout<<type<<". "<<definition<<endl;}
		string getword(){return word;}
};
int cmp(Word a,Word b){return a.getword().length()<b.getword().length();}
class Dictionary{
	private:
		vector<Word> v;
	public:
		void loadDictionary(){
			ifstream fin("dictionary2020.txt");  
			string wor,def,typ;
			Word tmp;
			while(getline(fin,wor)){
				getline(fin,def);
				getline(fin,typ);
				tmp.getters(wor,typ,def);
				v.push_back(tmp);
				getline(fin,typ);//¶Áµô¿ÕÐÐ
				cout<<"loading dictionary: "<<wor<<endl;
			}
			fin.close();
			sort(v.begin(),v.end(),cmp);
			cout<<"load complete"<<endl;
		}
		void searchword(){
			cout<<"enter the word to search:";
			string word;
			cin>>word;
			for(int i=0;i<v.size();i++)
				if(v[i].getword()==word){
					v[i].printDefinition();
					return;
				}
			cout<<"word not found.\n";
		}
		void findlongest(){
			int maxlen=v[v.size()-1].getword().length();
			cout<<"longest words: "<<endl;
			for(int i=v.size()-1;i>=0;i--){
				if(v[i].getword().length()==maxlen){
					cout<<v[i].getword()<<" ";
					v[i].printDefinition();
				}
				else break;
			}
			cout<<endl;
		}
		void search_logy(){
			bool found=0;
			cout<<"words end in¡®logy¡¯and contain seven letters or less in total: ";
			for(int i=0;i<v.size();i++){
				if(v[i].getword().length()<=7){
					if(v[i].getword().length()>=4&&v[i].getword().substr(v[i].getword().length()-4,4)=="logy"){
						cout<<v[i].getword()<<" ";
						found=1;
					}
				}
				else break;
			}
			cout<<(found?"":"not found.")<<endl;
		}
};
int main(){
    Dictionary d;
    d.loadDictionary();
	int operation;
	while(1){
		cout<<endl<<"Menu: "<<endl;
		cout<<"1.Search word"<<endl;
		cout<<"2.Find the longest word"<<endl;
		cout<<"3.Find the words end in¡®logy' and contain seven letters or less in total"<<endl;
		cout<<"-1:quit"<<endl;
		cin>>operation;
		switch(operation){
		case 1:d.searchword();break;
		case 2:d.findlongest();break;
		case 3:d.search_logy();break;
		case -1:system("pause");return 0;
		default:cout<<"wrong instruction"<<endl;
		}
	}
    system("pause");
}