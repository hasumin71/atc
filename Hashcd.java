import java.math.BigInteger;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

// SHA-256（SHA-2）
public class Hashcd {
  public static void main(String[] args) throws NoSuchAlgorithmException {
    MessageDigest sha256 = MessageDigest.getInstance("SHA-256");
    byte[] sha256_result = sha256.digest("テスト1".getBytes());
    System.out.println("SHA-256：" + String.format("%040x", new BigInteger(1, sha256_result)));
  }
}


    //getInstanceとは
    //String 変数("SHA-256")アルゴリズムの名前を指定する変数;を受け取り、
    //指定されたアルゴリズムを実装したMessageDigestオブジェクトを返す。
    //メッセージを表すバイト配列を受け取り、それを上記で作成した MessageDigest オブジェクトに追加/渡すものです。//digestとは
    //書式付き出力
    //%は指定を開始する 
    //0は足りない桁数を穴埋めする
    //40は？最小フィールド幅を指定する
    //xは16進数
    //BigInteger Javaで数学的な処理をする際に、扱う数値がプリミティブデータ型では扱えない程大きい場合に利用します。
    //値に上限を持たせない
    //例えばがプリミティブデータ型の最大値は9223372036854775807
    //「メッセージダイジェスト」とは一方向ハッシュ関数とも呼ばれ任意の文字列から固定長のハッシュ値を生成するプログラム
    //0で埋められるケースとしては「%～x」で指定した桁数に満たない数値は足りない桁分0で埋められることになります。