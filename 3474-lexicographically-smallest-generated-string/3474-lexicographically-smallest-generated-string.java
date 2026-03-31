import java.util.*;

class Solution {
    public String generateString(String str1, String str2) {
        int n = str1.length(), m = str2.length(), totalLen = n + m - 1;
        char[] result = new char[totalLen];
        boolean[] fixed = new boolean[totalLen];
        Arrays.fill(result, '?');

        int i = 0;
        while (i < n) {
            if (str1.charAt(i) == 'T') {
                int j = 0;
                while (j < m) {
                    int pos = i + j;
                    if (result[pos] == '?') {
                        result[pos] = str2.charAt(j);
                        fixed[pos] = true;
                    } else if (result[pos] != str2.charAt(j)) {
                        return "";
                    }
                    j++;
                }
            }
            i++;
        }

        int idx = 0;
        while (idx < totalLen) {
            if (result[idx] == '?') {
                result[idx] = 'a';
            }
            idx++;
        }

        int p = 0;
        while (p < n) {
            if (str1.charAt(p) == 'F') {
                boolean match = true;
                List<Integer> freeIndices = new ArrayList<>();
                int q = 0;
                while (q < m) {
                    int pos = p + q;
                    if (result[pos] != str2.charAt(q)) {
                        match = false;
                        break;
                    }
                    if (!fixed[pos]) {
                        freeIndices.add(pos);
                    }
                    q++;
                }

                if (match) {
                    if (freeIndices.isEmpty()) {
                        return "";
                    }
                    int lastIdx = freeIndices.get(freeIndices.size() - 1);
                    boolean updated = false;
                    char ch = (char) (result[lastIdx] + 1);
                    while (ch <= 'z') {
                        if (ch != str2.charAt(lastIdx - p)) {
                            result[lastIdx] = ch;
                            updated = true;
                            break;
                        }
                        ch++;
                    }
                    if (!updated) {
                        return "";
                    }
                }
            }
            p++;
        }

        return new String(result);
    }
} 
