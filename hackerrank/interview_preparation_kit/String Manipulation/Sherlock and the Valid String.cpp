#include <bits/stdc++.h>

using namespace std;

string isValid(string s) {
    map<char, int> char_map;
    map<int, int> fre_map;
    for(int i =0; i <s.size(); i++) char_map[s[i]]++;
    for(auto x:char_map) fre_map[x.second] ++;

    auto norminal = *max_element(fre_map.begin(),fre_map.end(),[] (const std::pair<char,int>& a, const std::pair<char,int>& b)->bool{ return a.second < b.second; } );;
    bool sub_used = false;

    for(auto y: fre_map){
        if(y.first != norminal.first){
            if(abs(y.first - norminal.first) > 1) {
                if(y.first != 1 ) return "NO";
            }
            else if (abs(y.first - norminal.first) == 1){
                if(y.second > 1 ) return "NO";
                else if (y.second == 1  && !sub_used) sub_used = true;
                else if (y.second == 1  && sub_used) return "NO";
            }
        }
    }   

    // for(auto y: fre_map){
    //     if(y.first != norminal.first){
    //         if(y.first > 1) return "NO";
    //         else if(y.second > 1 ) return "NO";
    //         else if (y.second == 1  && !sub_used) sub_used = true;
    //         else if (y.second == 1  && sub_used) return "NO";
    //     }
    // }   

    return "YES";
}

int main(){
    // string s =  "ibfdgaeadiaefgbhbdghhhbgdfgeiccbiehhfcggchgghadhdhagfbahhddgghbdehidbibaeaagaeeigffcebfbaieggabcfbiiedcabfihchdfabifahcbhagccbdfifhghcadfiadeeaheeddddiecaicbgigccageicehfdhdgafaddhffadigfhhcaedcedecafeacbdacgfgfeeibgaiffdehigebhhehiaahfidibccdcdagifgaihacihadecgifihbebffebdfbchbgigeccahgihbcbcaggebaaafgfedbfgagfediddghdgbgehhhifhgcedechahidcbchebheihaadbbbiaiccededchdagfhccfdefigfibifabeiaccghcegfbcghaefifbachebaacbhbfgfddeceababbacgffbagidebeadfihaefefegbghgddbbgddeehgfbhafbccidebgehifafgbghafacgfdccgifdcbbbidfifhdaibgigebigaedeaaiadegfefbhacgddhchgcbgcaeaieiegiffchbgbebgbehbbfcebciiagacaiechdigbgbghefcahgbhfibhedaeeiffebdiabcifgccdefabccdghehfibfiifdaicfedagahhdcbhbicdgibgcedieihcichadgchgbdcdagaihebbabhibcihicadgadfcihdheefbhffiageddhgahaidfdhhdbgciiaciegchiiebfbcbhaeagccfhbfhaddagnfieihghfbaggiffbbfbecgaiiidccdceadbbdfgigibgcgchafccdchgifdeieicbaididhfcfdedbhaadedfageigfdehgcdaecaebebebfcieaecfagfdieaefdiedbcadchabhebgehiidfcgahcdhcdhgchhiiheffiifeegcfdgbdeffhgeghdfhbfbifgidcafbfcd";
    // string s =  "aaaaabc";
    string s = "abcdefghhgfedecba";
    string result = isValid(s);
    cout << result <<endl;
    return 0;
}