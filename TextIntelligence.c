#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[40];
    int count;
} WordStat;

int count_words(WordStat *w, int n) { return n; }

char* longest_word(WordStat *w, int n) {
    if (n == 0) return "no words";
    char *longest = w[0].name;
    for (int i = 1; i < n; i++)
        if (strlen(w[i].name) > strlen(longest))
            longest = w[i].name;
    return longest;
}
 
char* most_frequent(WordStat *w, int n) {
    if (n == 0) return "no words";
    WordStat *max_word = &w[0];
    for (int i = 1; i < n; i++)
        if (w[i].count > max_word->count)
            max_word = &w[i];
    return max_word->name;
}

float avg_word_length(WordStat *w, int n) {
    if (n == 0) return 0.0;
    int total = 0;
    for (int i = 0; i < n; i++)
        total += strlen(w[i].name);
    return (float)total / n;
}

int has_palindrome(WordStat *w, int n) {
    for (int i = 0; i < n; i++) {
        char *word = w[i].name;
        int len = strlen(word);
        if (len <= 1) continue;
        
        int is_pal = 1;
        for (int j = 0; j < len / 2; j++)
            if (word[j] != word[len - 1 - j])
                is_pal = 0;
        
        if (is_pal) return 1;
    }
    return 0;
}

int main() {
    int sid = 54321;
    printf("Student ID: %d\n\nEnter text:\n", sid);
    
    char *text = malloc(500);
    if (!text) { printf("Memory allocation failed\n"); return 1; }
    
    fgets(text, 500, stdin);
    printf("Text at: %p\n", (void*)text);
    
    WordStat *words = malloc(sizeof(WordStat) * 50);
    if (!words) { free(text); return 1; }
    
    int wcount = 0;
    char word[40];
    int widx = 0;
    
    char *p = text;
    while (*p) {
        char c = *p;
        int is_alpha = (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
        
        if (is_alpha) {
            if (c >= 'A' && c <= 'Z') c = c + 32;
            if (widx < 39) word[widx++] = c;
        } 
        else if (widx > 0) {
            word[widx] = '\0';
            
            int found = 0;
            for (int j = 0; j < wcount; j++) {
                if (strcmp(words[j].name, word) == 0) {
                    words[j].count++;
                    found = 1;
                    break;
                }
            }
            
            if (!found && wcount < 50) {
                strcpy(words[wcount].name, word);
                words[wcount].count = 1;
                wcount++;
            }
            widx = 0;
        }
        p++;
    }
    
    typedef char* (*AnalysisFunc)(WordStat*, int);
    AnalysisFunc analysis[] = {longest_word, most_frequent};
    char *names[] = {"Longest", "Most Frequent"};
    
    printf("\nWord array at: %p\n", (void*)words);
    printf("\n=== Analysis Results ===\n");
    printf("Total words: %d\n", wcount);
    
    for (int i = 0; i < 2; i++)
        printf("%s: %s\n", names[i], analysis[i](words, wcount));
    
    printf("Average length: %.2f\n", avg_word_length(words, wcount));
    printf("Has palindrome: %s\n\n", has_palindrome(words, wcount) ? "Yes" : "No");
    
    printf("--- Word List ---\n");
    for (int i = 0; i < wcount; i++)
        printf("%-15s (%d) at %p\n", words[i].name, words[i].count, (void*)&words[i]);
    
    free(words);
    free(text);
    return 0;
}