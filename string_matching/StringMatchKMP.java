class StringMatchKMP {
    public List<String> stringMatching(String[] words) {
        Set<String> uniqueWords = new HashSet<>(Arrays.asList(words));
        List<String> res = new ArrayList<>();
        for (String word: words) {
            if (match(uniqueWords, word)) {
                res.add(word);
            }
        }
        return res;
    }

    private boolean match(Set<String> words, String input) {
        for (String word: words) {
            if (word.length() > input.length() && stringMatch(word, input)) {
                return true;
            }
        }
        return false;
    }

    private boolean stringMatch(String word, String pat) {
        int len = word.length();
        int[] lps = lps(pat);
        int j = 0;
        for (int i = 0; i < len;) {
            if (word.charAt(i) == pat.charAt(j)) {
                ++j;
                ++i;  
                if (j == pat.length()) {
                    return true;
                }
            } else if (j > 0) {
                j = lps[j-1];
            } else {
                ++i;
            }
        }
        return false;
    }

    private int[] lps(String word) {
        int len = word.length();
        int[] lps = new int[len];
        for (int i = 1; i < len; ++i) {
            int j = lps[i-1];
            while (j > 0 && word.charAt(i) != word.charAt(j)) {
                j = lps[j-1];
            }
            if (word.charAt(i) == word.charAt(j)) {
                ++j;
            }
            lps[i] = j;
        }
        return lps;
    }
}