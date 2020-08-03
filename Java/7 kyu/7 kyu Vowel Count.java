public class Vowels {

  public static int getCount(String str) {
    int vowelsCount = 0;
    for(char ch: str.toCharArray())
      if("aeiou".indexOf(ch) != -1)
        vowelsCount ++;
    return vowelsCount;
  }

}