#include <bits/stdc++.h>
#include <string>
#include <iostream>
using namespace std;
string huffmancode[26];
// A Huffman tree node
struct MinHeapNode
{
    char data;             
    unsigned freq;             
    MinHeapNode *left, *right; 
 
    MinHeapNode(char data, unsigned freq)
    {
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

struct compare
{
    bool operator()(MinHeapNode* l, MinHeapNode* r)
    {
        return (l->freq > r->freq);
    }
};

void printCodes(struct MinHeapNode* root, string str)
{
    if (!root)
        return;
 
    if (root->data != '$')
    {
        cout << root->data << ": " << str << "\n";
		huffmancode[root->data-'a'] = str.c_str(); 
	}
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

void HuffmanCodes(char data[], int freq[], int size)
{
    struct MinHeapNode *left, *right, *top;

    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;
    for (int i = 0; i < size; ++i)
        minHeap.push(new MinHeapNode(data[i], freq[i]));
 
    while (minHeap.size() != 1)
    {

        left = minHeap.top();
        minHeap.pop();
 
        right = minHeap.top();
        minHeap.pop();
        
        top = new MinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }

    printCodes(minHeap.top(), "");
}

int main()
{
	 FILE *fp;
    int c;
	int count[26] = {0};
    fp = fopen("alice.txt", "r");
       FILE *fptr;

   fptr = fopen("binary1.txt", "w");
    if(fptr == NULL)
   {
      printf("Error!");
      exit(1);
   }
    while((c = fgetc(fp)) != EOF) {
      if (c >= 'a' && c <= 'z') 
         count[c-'a']++;
          if (c >= 'A' && c <= 'Z') 
         count[c-'A']++;
         int j = 0;
  
 

    }

    fclose(fp);
      
    int i = 0;

 for (i = 0; i < 26; i++)
   {

 
      if (count[i] != 0)
         printf("%c occurs %d times in the entered string.\n",i+'a',count[i]);
            
   }
	 char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' ,'g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	    int size = sizeof(arr) / sizeof(arr[0]);
		HuffmanCodes(arr, count, size);
		
		//for(int i=0;i<26;i++)
		char z = 'g';
			cout<<	huffmancode[z].c_str()<<endl;
		while((c = fgetc(fp)) != EOF)
		 {
			  char output[9];
      	if (c >= 'a' && c <= 'z') 
          fprintf(fptr,"%s",huffmancode[c-'a'].c_str());
        if (c >= 'A' && c <= 'Z') 
          fprintf(fptr,"%s",huffmancode[c-'a'].c_str());
  		else
  		{
			itoa(c, output, 2);
			fprintf(fptr,"%s", output);
		}
    }
fclose(fptr);
    return 0;
}
