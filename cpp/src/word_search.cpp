#include "utils.h"
#include <queue>

using namespace std;


class Solution{
 public:
  bool exist(vector<vector<char> > &board, string word){
    if (board.size()==0){
      return word=="";
    }

    int row=board.size();
    int col=board[0].size();
    vector<vector<bool> > mark(row);
    for (int i=0; i<row; ++i){
      mark[i]=vector<bool>(col);
      for (int j=0; j<col; ++j){
        mark[i][j]=false;
      }
    }

    for (int i=0; i<row; ++i){
      for (int j=0; j<col; ++j){
        if (board[i][j]==word[0]){
          mark[i][j]=true;
          if (exist0(board, word, row, col, i, j, 0, mark)){
            return true;
          } else{
            mark[i][j]=false;
          }
        }
      }
    }

    return false;
  }

 private:
  bool exist0(vector<vector<char> > &board, string &word,
              int row, int col,
              int c_row, int c_col, int c_idx,
              vector<vector<bool> > &mark){
    if (c_idx==(int)word.size()-1){
      return true;
    }

    bool ok=false;
    if (c_row>0 && board[c_row-1][c_col]==word[c_idx+1]
        && !mark[c_row-1][c_col]){
      mark[c_row-1][c_col]=true;
      ok=exist0(board, word, row, col, c_row-1, c_col, c_idx+1, mark);
      mark[c_row-1][c_col]=false;
    }

    if (!ok && c_col+1<col && board[c_row][c_col+1]==word[c_idx+1]
        && !mark[c_row][c_col+1]){
      mark[c_row][c_col+1]=true;
      ok=exist0(board, word, row, col, c_row, c_col+1, c_idx+1, mark);
      mark[c_row][c_col+1]=false;
    }

    if (!ok && c_row+1<row && board[c_row+1][c_col]==word[c_idx+1]
        && !mark[c_row+1][c_col]){
      mark[c_row+1][c_col]=true;
      ok=exist0(board, word, row, col, c_row+1, c_col, c_idx+1, mark);
      mark[c_row+1][c_col]=false;
    }

    if (!ok && c_col>0 && board[c_row][c_col-1]==word[c_idx+1]
        && !mark[c_row][c_col-1]){
      mark[c_row][c_col-1]=true;
      ok=exist0(board, word, row, col, c_row, c_col-1, c_idx+1, mark);
      mark[c_row][c_col-1]=false;
    }
    return ok;
  }
};


static vector<vector<char> > build_board(char *s, int row, int col){
  vector<vector<char> > m(row);
  int k=0;
  for (int i=0; i<row; ++i){
    m[i]=vector<char>(col);
    for (int j=0; j<col; ++j){
      m[i][j]=s[k++];
    }
  }
  return m;
}


int main(int argc, char **argv){
  //char *str=(char *)
  //    "pfhnuvuzzpujstpivosmqlctynsputylyiaufutfjnqdjfnevftotvhticjevjrvrrpxl"
  //    "kewzubibppwwikpdulnwusrdjoxbdwopalowoxxdotcwgrzaeowygpesddvizjzbwnxlm"
  //    "uqanswtmxvqorruixonajvbvuctkzgwtxzirxedxzwltphbmwpmhmncjpwvqctjbsttsx"
  //    "ypxwcqljtxfklpxarirpdhuwsxpmqjjryinaabluytekidkblerolnnekeqdnbulkjnkk"
  //    "ygltlxbqhdclwszjfftjvwwysjkeyxqxdbqqyuhixlvvduelbzwwytxqehwdenckquarq"
  //    "jznuwiatonuojtmeqejzbogqsqimszdcysyvdaqrnkhxdtdtyovbcbtwrbjlbonbioynq"
  //    "ohezodciiyixvlbweypfjagxqihegvuvcawsfacoyklvvmrbkghthnsxxcdexzbbcxthx"
  //    "wxyiitgxnhjtqfcgxbdbejygmbilxrjvpjfzelwtvinlnrtmtxoziofvqngnfrkwcpvhd"
  //    "scycplpjhbcepbmehhwwqldhvzkkvtnpvnrnbgwijyozbcfkmbhcmkjjmvthojykyrzbx"
  //    "vjivzjycojorqqfcbooxixltvxrowtntewqefpgwywnqotuphjmriakgzcuyxitbekflz"
  //    "nhzjvpzqlpxwdpffbnfdhfarycxijjjzqiknzkdlzdhesoktbpzlubcufadrloqbzarak"
  //    "unlxxqrlanproanpehvemmpbetcekcrgqegnwxaympparcqwmnaybsbfndlxgcfwjllfj"
  //    "levdvwuyoqmbtkclmjaruxxxeviqinbutwxpurpkkdndnrqbaqtvpsutqcjyrksnjrefl"
  //    "vsvyfanxspxikuzeouusgtmqnzbffjqabnygpnfhcfrozqtokniqiujwvmbavtayiahxo"
  //    "mesrvjrnchxrrqambwjnzklsmjcpszfffxycgrrkaqesgeghcpvbbivqrxfmykrfjrhsj"
  //    "aejqidxmjgqbbreloufnzrllisxbbpkbtwscbpqnvhozaskpnpcoiqcqizskoeljcfleu"
  //    "crslhtlbfaqxfffvhyfgsrwwffbktfhxybifutgbwxybeeyleftwxrucyvorcvoayyfss"
  //    "ouqlutparcewxcvqxxouogxjwxivfcptyfgvyxvrbcpyelobkeyykvkjuuezytuxaauax"
  //    "ptytiyytobetzefuoopksqjnlipncpntilntmlocmuvozdiprzamsjbfrrstifmttbmfm"
  //    "ahbxfpwizlbblptwrynkqisyxnrybynehobodxyekafypyuiykspsnpragqegdintleyi"
  //    "ccucisuinchxvyrinjktzobeyqxjuvtxxobhgvqvyxuvxmfkvpfwggaewzotuhqtxrben"
  //    "tbnswkpipzfggbmmdtkchdwqtrqnuwcnxphtzwdqxiwdjjrmccolfmdbgtqapsqpjxikw"
  //    "matuwzghqslujycvefbzvernugyrqinekjziihsazdviexgicjjznaohimzzwodgxeqhl"
  //    "iknofvsedcinnjaoxkyjlxfbdnbjdixoskczhwflapanycdvmcgzblbgacqgknufxyggu"
  //    "orudrjcunzirgiutjbultcxgwefullqzfmewvgskgbdojyhuzdfsfeabjfxuspvxbzwzi"
  //    "olqrpecnnwordgwiiarpznhpkhsldtvtfnlurnjhmxypfuznwscwhlnrshfvbapiocchp"
  //    "nodmovrlughnifutsooatjdvallcptucjzoyuhjpnsexyyssogujsxfuiqxxltbxsrxny"
  //    "ienaimaihtxnnghllcvebvrwwooqldqtjewrswazrzpffwstapxbkqxjfozstpodvkwog"
  //    "ypaxefddzydoxhbngkuwjnqybvwlrktsbtpgaulbsqqpxrdedxammsmnniahuwbwpqesl"
  //    "rtdhlvfealhzlvmgibvscenyflpwphjgdonojuvlfcltyxziyuaczpagaqcrzlzccptlj"
  //    "oxpskkshjahfbkgsmntcrkcfkghzzukntzgdlymwzwccikwuzpxrabwmhflhzxwvxcykd"
  //    "nhejjirvelvukmwnkivrvessanrfocibjmkuudpyomsbyookyldtrwmujfzxhjysvkopn"
  //    "epeskftavdzjhsafgwomvoveoobzesmiisdsxwuvzteiognudeiysgfgwghabwljoodmk"
  //    "zhjtnuhtjdwnoxhucqqkxqntbwkpbwzbflwuhfnqikgwjpqnfgxfzlaajksnitqpeojnt"
  //    "xgbjmaubqhjzeqyrqadbusloibuwkirjosucsoflvokcektxmyahqlvamryzbpkpiftcv"
  //    "znrpzvwjqtypvfhgcivtgwxwgogniijjwcyxxwhprhemmmtquqlcmiysxeifprqnvokun"
  //    "rjeyormcmeyeqaqabkxhsewlujgluaynkeoavcejhcnzedzhqxpidnwazcltflirpyrnb"
  //    "xwkzmjfrknhjesnropqqalvnuoeufrxcqhdcsltdybmctbvjqmzsxxhtlmqtdnxvxdxro"
  //    "tuowjsrmnafzzxzyhumtmhyaguzltqzmnpiwhzkvzpwbpxbwunrgwpidjhodyqrlfajpz"
  //    "vkbliecgfaavririrwuynzyfqjmqubsqlvdwzhcgjebcmvkdtgegfclyoaqibkapfflgo"
  //    "nnxtobflmjfunlarzyfzqqcbsrgacnoraokqpqcdbhyquahvanwqfzrxsaxvnoopczhrr"
  //    "lxsuvkpxrmxglpnkhlchkzwyonanuuggraaokrndgkkrzxbikfrvfnvvaykxuqdnqfbaz"
  //    "odfapybpbmbgdynruktsuqmkvzcdcecskjubhxqkjusnsigmszgnqsznteqxispsdlumj"
  //    "mwsgphzxnnrpugfogsikjhudznhkjvtvsocjvdglqzakghzmzjykqsqrhzcquxmmlqvjt"
  //    "dujduwjbvxcgxpyrfqzgspardpdtkooqiyteuehrdlzaaxrhnqnhiqbnfgjruxhexciti"
  //    "rmlcllfjfmyxcihujvzpeqjbanbcxulojysumxfrmeoqmwkvtjmxbvabkdgjatzjrrddp"
  //    "jwbnnrblbyemkbphdtthzchubqnsvrjepktcdwngwruiukpadkheoqypilkdetkugdylc"
  //    "muyfohcyycbjlhxbfpjtbmxuytccsqggkenynpzmtaxeiufplqimfgjdbnhtdnbpupohg"
  //    "nvapsezpmraeznjhypjlwermiggzwpfllhbdmcsatvevkqcifnvdumpcvxbrnifyqgdek"
  //    "ygetmzfcdnjrknnzcpwcsnpaupscswnsetlruqtxfdqssdrwunymcppxehzzgorkhfbbv"
  //    "xbdarxuvoqpdrehgtglaimiwdteiuhgriltaipxygodzukfntsqbeyxktdsqnahvldxts"
  //    "wtalwzhjhvczndgncqjgizvjiqwlosgmlixkkhtrevsraygcopkzqfkzyimmasymdywnh"
  //    "relmweoxkqncdmskytihgwhaxvdxtqekwpyvvosfhfjkueuuxfbdbleaijxeadqyuptpd"
  //    "nvmvgwpktlkapnbctekdbofhfdbwzrbmoohumyhhkrhzgldapnfsekzlpbjoumdickepl"
  //    "lwxeeylrbngqsaucahtdqixdlhfxlwkxvhbbfosibaztavxadrfvbeymlglxewuzfxcnm"
  //    "uvpuwjxsixvzfqajrovzcsfyohfnjsbgqrcmazeixbkesmnldimfcrfsykgifhovyshas"
  //    "mlrpvvjjiumtirxayqajwiofylersgjgrawoxfyfckakeymcqnnoxdtwozpjgapxcnmzt"
  //    "mgxwjhcjufzjsngyicmitvqvnnzabavnjsmscobytchopnoxschnyxjnnknqlleudsmhg"
  //    "pfcrosicghwipjiouvbfluqwykbsylynsaghuolavhlmqtbnreseyicyufquqrjjtpsof"
  //    "doakbpcvqpowjuxtwvpbojufudyjvmqadtkeiobagrwpltlhralhkfmgkmqhzihebtkjj"
  //    "ojrfihtduawundgupneefndnwjpptabhmspubizvkwsybystnzxsocillzcezdonwdjzl"
  //    "jvvhnvknqdbpavdefopgrwiwmvspfscqpzzevjrlnucpsfuxwjephmltjgkoamgpmftjp"
  //    "muchwtzdnybzeqgsecckmskzzbneuwvgszpototipvhtnqorsqdekpdlqsqkontgniwgz"
  //    "sqonyjcozwipzmcpsnhkfsztnhiveqwwgmleypuxlepnrrelenvmfwfugnskdoijbvqbm"
  //    "myarnpkgtvngszopgkvtchyrrjuobxaovahlprrkoetgfjxltugwdgpwqlktilhflqqdj"
  //    "knxoggwpfhlcojfuycmlogvzpangtqrdfrtoxpfexqgnzmjzqwkeehgtivbbnvgsmzglp"
  //    "opoewbgkkfaisgobokjjnmwisruuxfjnvxutaadmhfxbnldcvonjdkrxboravcosbilbk"
  //    "qqrvnvjyynuoafrmwppmgqijgakqooceevcrqnrqalfcswppnedwwlfeorwefyilukckx"
  //    "udzhicagtrwzusyixeyqbcybmjvzoiyilarvetdxkzyhryrqdrjgvhhhqdienjoajixnb"
  //    "ammckvvjmmodxuyebhwgsbtbrvkzszdtlpxxmsiagwfdsdjumgcejyhattcosfjfwgdiy"
  //    "nkhmpkeuuagafnjdwlyqnmiuvqqdtacikjubvbvrberirclnqmffyoaweszzvdjhoejmh"
  //    "edikxtbzerrswxtmzpsrqtowdwmjhyqncaybtbcauustrnhsealxvatayhlhgdukeslzw"
  //    "nbqjwjcjruotglqigrinepvijhoeunairstncwyvsoqabgihzsxehuotccxwrzgiraxvy"
  //    "yqqmgropbxouuubpiwrktpcuwmmykjwiaowifkxjiodeigtrdmbycftashyeqwoskkdsv"
  //    "abfogjzmfqprrovzjxrqvvitjbgveysgbxxhjwtomlhfbdekaxcysktdnzbrztaarxhcv"
  //    "dqjqxorcvddshdnrwsfwtyxnaygxhiumydcxstapyfhfiwzgpgcigaxhadghnbwneylyu"
  //    "nnssxactzikfntnpsupwbylcuzivmhpzwjttjvpkfzrsufhnzylczwetxpojwfkupfoaa"
  //    "fliecazhkojizlhvsdvjtefzrbqwrqzwbhbghcptqacrmjogojpiqwjhxzdppentlozvs"
  //    "qokrsbfcqlsbcarajyzieoaietwsurnkhxdabietvwuzzmzimztqptbtoxoiqduxcazdi"
  //    "dygctfbhhjtgemxxntnkjxcmsbqsbucguiinqjuxvqfzcczrxmdikfuegnyhhcqblyrdk";
  //vector<vector<char> > board=build_board(str, 80, 69);
  char *str=(char *)
      "ABCE"
      "SFES"
      "ADEE";
  vector<vector<char> > board=build_board(str, 3, 4);
  Solution s;
  //debug_log("%d\n", s.exist(board, "afdfghjhy"));
  debug_log("%d\n", s.exist(board, "ABCESEEEFS"));
  return 0;
}
