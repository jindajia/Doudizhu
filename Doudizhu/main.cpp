
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
//斗地主
enum suit{spade,hearts,clubs,diamonds,small,big};
string suit_str[]={"黑桃","红心","梅花","方片","小","大"};
map<string,int> map_Power;
class Poker{
    suit type;//表示牌的花色
    string number;//表示牌的点数
    int power;//表示牌力大小；大王>小王>2>A>K>Q>J>10>......3//大王的牌力是15
public:
    Poker(suit t,string n):type(t),number(n),power(map_Power[suit_str[t]+n]){}
    bool operator<(const Poker& p)const{
        return power<p.power;
    }
    bool operator>(const Poker& p)const{
        return power>p.power;
    }
    string to_string(){
        string s=suit_str[type];
        s+=number;
        return s;
    }
    int getPower()const{
        return power;
    }
};
class DeckCards{
public:
     vector<Poker> v;
    DeckCards(){
        for(int i=3;i<=10;i++){
            
            for(int j=0;j<4;++j){
                map_Power[suit_str[j]+to_string(i)]=i-2;
                v.push_back(Poker((suit)j,to_string(i)));
            }
        }
        for(int j=0;j<4;++j){
            map_Power[suit_str[j]+"J"]=9;
            v.push_back(Poker((suit)j,"J"));
        }
        for(int j=0;j<4;++j){
            map_Power[suit_str[j]+"Q"]=10;
            v.push_back(Poker((suit)j,"Q"));
        }
        for(int j=0;j<4;++j){
            map_Power[suit_str[j]+"K"]=11;
            v.push_back(Poker((suit)j,"K"));
        }
        for(int j=0;j<4;++j){
            map_Power[suit_str[j]+"A"]=12;
            v.push_back(Poker((suit)j,"A"));
        }
        for(int j=0;j<4;++j){
            map_Power[suit_str[j]+"2"]=13;
            v.push_back(Poker((suit)j,"2"));
        }
        map_Power["小鬼"]=14;
        v.push_back(Poker((suit)4,"鬼"));
        map_Power["大鬼"]=15;
        v.push_back(Poker((suit)5,"鬼"));
        
        
    }
    void print(){
        for(auto a:v){
            cout<<a.to_string()<<endl;
        }
    }
};
class Play{
public:
    vector<Poker> v;
    Play(vector<Poker> v1):v(v1){
        sort(v.begin(),v.end());
    }
    bool operator<(const Play& p2)const{
        int size=p2.v.size();//p2的张数
        if(p2.v.size()!=v.size()){//当出牌张数不同时，只有一种可能，炸弹
            if(size==2){
                return p2.v[0].getPower()==14&&p2.v[1].getPower()==15;
            }
            else if(size==4){
                //当p不是炸
                if(v.size()!=4||v[0].getPower()!=v[3].getPower())
                    return p2.v[0].getPower()==p2.v[3].getPower();
                else
                    return p2.v[0].getPower()==p2.v[3].getPower()&&p2.v[0].getPower()>v[0].getPower();
            }
            else{
                return false;
            }
        
        }
        else{
            //首先判断牌型
            if(size==1){
                return v[0].getPower()<p2.v[0].getPower();
            }
            else if(size==2){
                if(p2.v[0].getPower()==14&&p2.v[1].getPower()==15)
                    return true;
                else{
                    
                }
                    
            }
            else if(size==3){
                
            }
            else if(size==4){
                
            }
            else if(size==5){
                
            }
            else if(size==6){
                
            }
            else if(size==7){
                
            }
            else if(size==8){
                
            }
            else{
                
            }
        }
        return false;//为防止报错，随意写的
    }
};
int main(){
    DeckCards d;
    d.print();
    vector<Poker> v1;
    vector<Poker> v2;
    v1.push_back(Poker((suit)0,"2"));
    v2.push_back(Poker((suit)1,"A"));
    cout<<d.v.size();
    Play p1(v1);
    Play p2(v2);
    cout<<(p2<p1);
}

