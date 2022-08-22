for (int ori = m; ori > 0; ori--){
    for (int i = 0; i <= m - ori; i++){
        string new_stamp = string(i, '*') + stamp.substr(i, ori) + string(m - ori - i, '*');
        cout << new_stamp << endl;
    }
}


/*
absdg
absd*
*bsdg
abs**
*bsd*
**sdg
ab***
*bs**
**sd*
***dg
a****
*b***
**s**
***d*
****g
*/
