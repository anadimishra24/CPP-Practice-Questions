#include <bits/stdc++.h>
#include <iostream>
using namespace std;



// function for checking the number of two
bool powerOfTwo(int n){

    for (int i = 0; i < 30; i++)
    {
       int ans = pow(2, i);
       if(ans == n){
        return true;
       }
    } 
    return false;
}

char isLower(char ch){
    char ans;
    if(islower(ch)){
        return ch;
    }
    else{
        ans = ch - 'A' + 'a';
        return ans;
    }
}

bool isPalindrome(string s) {

        int start = 0;
        int end = s.size()-1;

        while(start < end){
            while (start < end && !isalnum(s[start])) {
                start++;
            }
            while (start < end && !isalnum(s[end])) {
                end--;
            }
            
            if(isLower(s[start]) == isLower(s[end])){
                start++;
                end--;
            }
            else{
                cout << "Else = " << s[start] << s[end] << endl;
                return 0;
            }
        }
    return 1;  
}

string gcdOfStrings(string str1, string str2) {

/* It is working fine but failed one test case don't know why becaue 
i got the answer as expected but it still says not as expected output 
    int start = 0, end = str2.size()-1;
    string ans = "";
    int pivot = 0;

    while(str1[start] != str2[end]){
        if(str1[end] != str1[start]){
            end--;
        }
        else{
            pivot = end-1;
            break;
        }
    }
    cout << pivot <<endl;
    while(pivot !=0){
        if(str1[start] != str2[pivot]){
            cout << "else m" << endl;
            return ans;
        }
        else{
            
            ans += str2[pivot];
            cout << ans << endl;
            start++;
            pivot++;;
        }
    }
    // cout << ans[0]<<endl;
    //     cout << ans[1]<<endl;
    // cout << ans[2]<<endl;
    // cout << ans[3]<<endl;


    return ans;
    */


   // this code works properly but here it not able to fetch gcd due to library issue but successfully accepted in leetcode
    // return (str1 + str2 == str2 + str1)? str1.substr(0, gcd(str1.size(),str2.size())): "";
}

string reverseWords(string s) {

    istringstream iss(s);
    vector<string> token;
    string word;
    int i = 0;

    while (iss >> word) {
        token.push_back(word);
    }

    reverse(token.begin(), token.end());
    string result;
    while(i < token.size()){
    //for (int i = 0; i < token.size(); ++i) {
        if (i > 0) result += " ";  
        result += token[i];
        i++;
    }

    return result;
/*
    char *str = new char[s.length() + 1]; 
    strcpy(str, s.c_str());
    char * token;
    //char *ans = new char[s.length() + 1];
    //printf ("Splitting string \"%s\" into tokens:\n",s);
    token = strtok (str," ");
    while (token != NULL)
    {
        printf ("%s\n",token);
        
        token = strtok (NULL, " ");
    }
    */    
}

/* Recursion method
vector<int> product(vector<int> &nums, int str_indx, vector<int> &res){
        int prod = 1;
        
        if( str_indx == nums.size()){
           return res;
        }

        for (int i = 0; i < nums.size(); i++){
            
            if(i == str_indx){
                continue;
            }
            else{
                prod = prod * nums[i];
            }
        }
        res.push_back(prod);
        return product(nums, str_indx+1, res);
}

*/
vector<int> productExceptSelf(vector<int>& nums) {
        /* recursion part
        int str_indx = 0;
        vector<int> res;
        vector<int> ans  = product(nums, str_indx, res);
        return ans; */

    int n = nums.size();
    vector<int> leftProducts(n, 1);
    vector<int> rightProducts(n, 1);
    vector<int> result(n);

    for (int i = 1; i < n; ++i) {
        leftProducts[i] = leftProducts[i - 1] * nums[i - 1];
    }

    for (int i = n - 2; i >= 0; --i) {
        rightProducts[i] = rightProducts[i + 1] * nums[i + 1];
    }

    for (int i = 0; i < n; ++i) {
        result[i] = leftProducts[i] * rightProducts[i];
    }

    return result;
}

bool check(vector<int>& candies, int d, int str_indx){
    for (int i = str_indx+1; i < candies.size(); i++){
        if(d < candies[i]){
            return false;
        }
    }
    return true;
}

vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        
        /* Submitted this code
        int size = candies.size();
        vector<bool> res(size,true);

        for(int i = 0; i < size; i++){
            int extra = candies[i] + extraCandies;
            cout << "extra = " << candies[i] << " + "  << extraCandies << " --> " << extra << endl;
            for(int j = 0; j < size; j++){
                if(extra < candies[j]){
                    cout << "false at j = " << j << " value = " << candies[j] << endl;
                    res[i] = false;
                    break;
                }
            }
          
        }
        */
    
    /* Second approach with less time complexity*/
    int size = candies.size();
        vector<bool> res(size,true);

        int maxCandy = *max_element(candies.begin(), candies.end());
        for(int i = 0; i < size; i++){
            int extra = candies[i] + extraCandies;
            if(extra < maxCandy){
                res[i] = false;
            }
          
        }
    
    return res;
}
bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
           c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

string reverseVowels(string s) {
        int start = 0;
    int end = s.size() - 1;

    while (start < end) {
        while (start < end && !isVowel(s[start])) {
            cout << "Start = " << s[start] << endl;
            start++;
        }
        while (start < end && !isVowel(s[end])) {
            cout << "End = " << s[end] << endl;
            end--;
        }
        if (start < end) {
            cout << "Swap start " << s[start] << " and end " << s[end] << endl;
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }

    return s;
}


bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    

    int flower = 1, i = 0, count = 0;
    while(count < n && i < flowerbed.size()) {
        if(flowerbed[i] == 0 && 
        (i == 0 || flowerbed[i-1] == 0) && (i == flowerbed.size() - 1 || flowerbed[i+1] == 0)) { 
            flowerbed[i] = flower;
            count++;
            i += 2; 
        } else {
            i++; 
        }
    }
    return count == n;
}

void moveZeroes(vector<int>& nums) {    
    int size = nums.size();
    int zero = 0, j = 0,i = 0;
    vector<int> tmp(size);

    while(i < size){
        if(nums[i] == 0){
            zero++;
        }
        i++;
    }
    for (int i = 0; i < size; i++){
        if(nums[i] != 0){
            tmp[j] = nums[i];
            j++;
        }
    }
    while(zero){
        tmp[j] = 0;
        j++;
        zero--;
    }
    nums = tmp;

/* others code
    int ind = 0;
        
        for (int i = 0; i < nums.size(); ++i) 
        {
            if (nums[i] != 0) 
            {
                swap(nums[i], nums[ind]);
                ind++;
            }
        }
    */
}

bool isSubsequence(string s, string t) {

    int str_indx = 0;  // Index to track position in 's'
    int str_len = s.size();  // Length of 's'

    // Iterate through each character in 't'
    for (char c : t) {
        // Check if current character matches the required character in 's'
        if (str_indx < str_len && s[str_indx] == c) {
            str_indx++;  // Move to the next character in 's'
        }
        // If all characters of 's' are found, return true
        if (str_indx == str_len) {
            return true;
        }
    }

    // Check if we have gone through all characters in 's'
    return str_indx == str_len;
        
}

/* This logic got TLE while using it find maxArea
vector<int> nextSmallerIndex(vector<int> arr, int n) {
    
    vector<int> ans(n);

    for(int i = 0; i < n; i++){
        int str_indx = i;
        int curr = arr[i];
        for(int j = i+1; j < n; j++){
            if(arr[j] >= curr){
                str_indx = j;
            }
        }
        ans[i] = str_indx;
    }
    return ans;
}

vector<int> prevSmallerIndex(vector<int> arr, int n) {

    vector<int> ans(n);

    for(int i = n-1; i >=0; i--){
        int str_indx = i;
        int curr = arr[i];
        for(int j = i-1; j >=0; j--){
            if(arr[j] >= curr){
                str_indx = j;
            }
        }
        ans[i] = str_indx;
    }
    return ans; 
}
*/

int maxArea(vector<int>& height) {

    /* Approach 
       1. Two-Pointer Technique: This technique uses two pointers, one starting at the beginning of the array (left) 
       and one at the end (right). The area between the two pointers is calculated, and then adjustments are made based on
       which pointer has the shorter line height.

       2. Greedy Choice for Maximizing Area: By always moving the shorter line towards the center, you're making a greedy choice. 
       This choice is based on the understanding that the area is limited by the shorter line. Moving the shorter line could potentially 
       find a taller line that increases the area. If you moved the taller line instead, you would definitely decrease the width 
       (since the pointers are moving closer together) and you could not increase the height, which would mean the best you could 
       do is find a worse area.*/

    int left = 0, right = height.size() - 1;
    int max_area = 0;
    while (left < right) {
        // cout << " --------------------------------------" << endl;
        // cout << "left = " << left;
        // cout << " | right = " << right << endl;
        int h = min(height[left], height[right]);
        // cout << "h[l] = " << height[left] << "\nh[r] = " << height[right] << " min h = " << h <<endl;
        int w = right - left;
        // cout << "w = " << w << endl;
        max_area = max(max_area, h * w);
        // cout << "max area = " << max_area << endl;

        if (height[left] < height[right]){
            // cout << "in if cond height[left] < height[right]: " << height[left] << " " <<height[right] << endl;
            left++;
            // cout << "left++ =" << left <<endl;
        }
        else{
            right--;
            // cout << "in else: " << right << endl;
        }
    }
    return max_area;
}

vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            for(int j = i+1; j < nums.size();j++){
                int sum = nums[i] + nums[j];
                cout << "Sum = " << sum << endl;
                if(sum == target){
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
}

bool increasingTriplet(vector<int>& nums) {

/*
    int i = 0, j = i+1, k = j+1, size = nums.size();
    while(k < size){
        if(nums[i] < nums[j]){
            if(nums[j] < nums[k]){
            return true;
        }
        else{
            i++;
            j++;
            k++;
        }
    } 
    return false;       
}
*/

// 20,100,10,12,5,13

    int a = INT_MAX;
    int b = INT_MAX;
    
    for (int num : nums) {
        if (num <= a) {
            a = num;
            cout << "a = " << a << endl;
        } else if (num <= b) {
            b = num;
            cout << "b = " << b <<endl;
        } else {
            cout << "num = " << num << endl;
            return true;
        }
    }
        
    return false;
}

vector<int> countBits(int n) {

    vector<int> ans(n+1, 0); // Initialize a vector of size n+1 with all zeros

    for(int i = 0; i <= n; i++){
        int count = 0;
        int number = i;
        while(number != 0){
            count += number & 1; // Increment count if the lowest bit is 1
            number = number >> 1; // Shift bits to the right
        }
        ans[i] = count;
    }
    return ans;


}

int maxOperations(vector<int>& nums, int k) {

    unordered_map<int, int> num_count;
    int operations = 0;
    
    for (int num : nums) {
        int complement = k - num;
        
        // Check if the complement exists and has a positive count
        if (num_count[complement] > 0) {
            operations++; // Found a pair
            num_count[complement]--; // Use up one occurrence of the complement
        } else {
            // Increment the count of the current number
            num_count[num]++;
        }
    }
    
    return operations;
}

int compress(vector<char>& chars) {

/*
    map<char, int> char_count;

    vector<int> arr;
    for(auto ch: chars){
        char_count[ch]++;
    }
    
    // Printing the count of each character
    for(const auto& pair : char_count) {
        cout << "Character '" << pair.first << "' appears " << pair.second << " times.\n";
    }
    for( const auto& vh: char_count){
        arr.push_back(static_cast<int>(vh.first));
        arr.push_back(vh.second);

    }
    for (auto count: arr){
        cout << count << " ";
    }
    return 0;
    */
    

    int size = chars.size();
    int index = 0;  // This will track where to insert in the chars array

    for (int i = 0; i < size; ) {
        char currentChar = chars[i];
        int count = 0;

        // Count how many times the character repeats
        while (i < size && chars[i] == currentChar) {
            i++;
            count++;
        }

        // Place the character back into the array
        cout << "chars[" << index <<"] = " <<  currentChar << endl;;
        chars[index++] = currentChar;

        // If count is more than 1, convert it to string and place each digit
        if (count > 1) {
            string countStr = to_string(count);
            for (char c : countStr) {
                chars[index++] = c;
            }
        }
    }

    return index;  // The new length of the array
}

int mySqrt(int x) {

    // the cases for x = 0 and x = 1.
    if (x < 2) return x;  

    int start = 1; 
    int end = x / 2;

    while(start <= end){
        int mid = start + (end - start) / 2;
        long long sq_rt = (long long)mid * mid;
        if(sq_rt == x){
            return mid;
        }
        else if(sq_rt > x){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    } 
    return end;
}

/* Add two number */
class ListNode{
public:
    int data;
    ListNode *next = NULL;
};

// print the LL
void printList(ListNode* node){
    while (node != NULL) {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout << "NULL";
}

// add the element at the end
void append(struct ListNode** head, int node_data){

    /* 1. create and allocate ListNode */
    struct ListNode* newNode = new ListNode;
    
    struct ListNode *last = *head; /* used in step 5*/
    
    newNode->data = node_data;
    newNode->next = NULL;
    
    if (*head == NULL){
        *head = newNode;
        return;
    }
    
    while (last->next != NULL){
        last = last->next;
    }

    last->next = newNode;
    return;
}

// reverse the linked list
void reverseLL(ListNode* &head){
    ListNode* temp = head;
    ListNode* nextList = NULL;
    ListNode* prev = NULL;

    while(temp != NULL){
        nextList = temp -> next;
        temp -> next = prev;

        // move the prev and temp
        prev = temp;
        temp = nextList;
    }
    head = prev;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
    ListNode* ans = NULL;
    ListNode* head = ans;
    int digit = 0, sum = 0, carry = 0;

    while(l1 && l2){
        sum = carry + (l1 -> data + l2 -> data);
        cout << "Sum = " << sum << endl;
        digit = (sum % 10);
        carry = sum / 10;
        append(&ans, digit);
        l1 = l1 -> next;
        l2 = l2 -> next;
    }

    while(l1){
        sum = carry + (l1 -> data);
        cout << "Sum = " << sum << endl;
        digit = (sum % 10);
        carry = sum / 10;
        append(&ans, digit);
        l1 = l1 -> next;
    }

    while(l2){
        sum = carry + (l2 -> data);
        cout << "Sum = " << sum << endl;
        digit = (sum % 10);
        carry = sum / 10;
        append(&ans, digit);
        l2 = l2 -> next;
    }

    if(carry != 0){
        append(&ans, carry);
    }

    //reverseLL(ans);
    printList(ans);
    return ans;
}
/* End of add two number*/

int romanToint(char ch){
    if(ch == 'I'){
        return 1;
    }
    else if(ch == 'V'){
        return 5;
    }
    else if(ch == 'X'){
        return 10;
    }
    else if(ch == 'L'){
        return 50;
    }
    else if(ch == 'C'){
        return 100;
    }
    else if(ch == 'D'){
        return 500;
    }
    else if(ch == 'M'){
        return 1000;
    }
}

int romanToInt(string s) {
        int num = 0;
        int size = s.size();
        cout << "Size = " << size << endl;
        if(size <= 2){
            int i = 0;
            num = romanToint(s[i+1]) - romanToint(s[i]);
            return num;
        }
        else{
            for(int i = 0; i <  s.size(); i = i+2){
                //if(romanToint(s[i]) < romanToint(s[i+1])){
                    cout << "s["<<i<<"] = " << s[i] <<   " and s["<<i+1<<"] = " << s[i+1] << endl; 
                    num += romanToint(s[i]) + romanToint(s[i+1]);
                    cout << "num == " << num << endl;
            // }
                
            }
        }
        return num;
}

int largestAltitude(vector<int>& gain) {
        
    int alt = 0;
    int max_alt = 0;

    for (int g : gain){
        alt = alt + g;
        if(alt > max_alt){
            max_alt = alt;
        }
    }
    return max_alt;
}

int pivotIndex(vector<int>& nums) {
    int prefixSum = 0, leftSum = 0;
    for (int num : nums) {
        prefixSum += num;
    }

    for (int i = 0; i < nums.size(); i++) {
        // Right sum for index i is prefixSum - leftSum - nums[i]
        if (leftSum == prefixSum - leftSum - nums[i]) {
            return i;
        }
        leftSum += nums[i];
    }

    return -1; // return -1 if no pivot index is found
}

int singleNumber(vector<int>& nums){
    
    int unique = 0;
    for (int num : nums) {
        // Apply XOR for each element because 𝐴 ⊕ 𝐴 = 0 for any element A
        unique ^= num;  
    }
    return unique;
}

bool uniqueOccurrences(vector<int>& arr) {

    // store the # occurrence of every element
    unordered_map<int,int> count;
    for (int num: arr){
        count[num]++;
    }

    // store the unique # occurrence because it is set 
    unordered_set<int> unique_occ;
    for (const auto &val: count){
        unique_occ.insert(val.second);
    } 

    // if both occurrence and unque_occ have same size then return true
    return count.size() == unique_occ.size();   
}

int scoreOfString(string s) {
    int score = 0;
    for (size_t i = 0; i < s.size()-1; ++i) {
        score += abs(static_cast<int>(s[i]) - static_cast<int>(s[i+1]));
        std::cout << "ASCII value of '" << s[i] << "' is: " << score << std::endl;
    }
    return score;
}

string defangIPaddr(string address) {
    string ans;  

    // "255[.]100[.]50[.]0"
    for(int i = 0; i < address.size(); i++){
        if(address[i] == '.'){
            ans.append("[.]");
        }
        else{
            ans.push_back(address[i]);
        }
    }
    return ans;
}

int numIdenticalPairs(vector<int>& nums) {

/* Its TC is O(n*m)
    int count = 0;

    for(int i = 0; i < nums.size(); i++){
        for(int j = i+1; j < nums.size(); j++){
            if(nums[i] == nums[j]){
                count++;
            }
        }
    }
    return count; 
*/
    
/* Optimized solution */
    unordered_map<int, int> freq;
    int count = 0;
    for (int num : nums) {
        count += freq[num]; // Add the frequency of num to count
        freq[num]++; // Increment the frequency of num
    }
    return count;
}

vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {

/*
   This is printing fine but it have lots of complecity and exceeding TC and also
   1. Vector Initialization: You're trying to access elements of ans without initializing its size. You should either resize ans to the required size or use push_back to add elements dynamically.
   2. Indexing Out of Bounds: When accessing ans[m][n++], m and n are not properly managed, leading to potential out-of-bounds access.

   vector<vector<int>> ans;
   int m = 0, n = 0;
   int value = 0;
   for(int i = 0; i < nums1.size(); i ++){
    value = 0;
    n = 0;
    for(int j = 0; j < nums2.size(); j++){
        if(nums1[i] == nums2[j]){
            value = 0;
            break;
        }
        else{
            value = nums1[i];
        }
    }
    if(value != 0){
        cout << "value = " << value << endl;
        ans[m][n++] = value;
    }
    
    m++;
   }

    for(int i = 0; i < nums2.size(); i ++){
        value = 0;
        n = 0;
        for(int j = 0; j < nums1.size(); j++){
            if(nums2[i] == nums1[j]){
                value = 0;
                break;
            }
            else{
                value = nums2[i];
            }
        }
        if(value != 0){
            cout << "value = " << value << endl;
            ans[m][n++] = value;
        }
        m++;
    }
   return ans;

*/

    unordered_set<int> set1(nums1.begin(), nums1.end());
    unordered_set<int> set2(nums2.begin(), nums2.end());
    vector<vector<int>> result;

    vector<int> diffInNums1, diffInNums2 ;
    
    for(auto i:set1){
        if(set2.find(i)==set2.end()){
            diffInNums1.push_back(i);
        }
    }
    for(auto i:set2){
        if(set1.find(i)==set1.end()){
            diffInNums2.push_back(i);
        }
    }
        
    vector<vector<int>> ans;
    ans.push_back(diffInNums1);
    ans.push_back(diffInNums2);


    return ans;
}

int equalPairs(vector<vector<int>>& grid) {


    map<int,vector<int>> row;
    map<int,vector<int>> col;
    int eqPair = 0;

    // store the matrix as row wise
    for(int i = 0; i < grid.size(); i++){
        row[i] = grid[i];
    }
    
    // Store the matrix, column wise
    for (int j = 0; j < grid[0].size(); ++j) {
        vector<int> column;
        for (int i = 0; i < grid.size(); ++i) {
            column.push_back(grid[i][j]);
        }
        col[j] = column;
    }

    /* Print the matrix stored row-wise
    cout << "Matrix stored row-wise:" << endl;
    for (auto it = row.begin(); it != row.end(); ++it) {
        int row_index = it->first;
        const vector<int>& row_values = it->second;
        cout << "Row " << row_index << ": ";
        for (int num : row_values) {
            cout << num << " ";
        }
        cout << endl;
    }
*/

    /* Print the matrix stored column-wise
    cout << "Matrix stored column-wise:" << endl;
    for (const auto& pair : col) {
        int col_index = pair.first;
        const vector<int>& col_values = pair.second;
        cout << "Column " << col_index << ": " ;
        for (int num : col_values) {
            cout << num << " ";
        }
        cout << endl;
    }
*/
   
    // calculation
    int sum = 0;
    for (auto i = row.begin(); i != row.end(); ++i) {
        int row_index = i->first;
        const vector<int>& row_values = i->second;

        for (auto j = col.begin(); j != col.end(); ++j) {
            sum = 0;
            int col_index = j->first;
            const vector<int>& col_values = j->second;

            for(int k = 0; k < col_values.size(); k++){
                cout << " Solution: " << sum << endl;
                sum = sum + abs(row_values[k] - col_values[k]);
            }
            if(sum == 0){
                eqPair++;
            }
        }
    }
    if(eqPair != 0){
        return eqPair;
    }
    else{
        return 0;
    }

    /* Optimized approach
    int n = grid.size(); // Get the size of the grid
        unordered_map<int, vector<int>> rowMap, colMap; // Maps to store row and column vectors

        // Iterate over the rows and columns of the grid
        for (int i = 0; i < n; ++i) {
            rowMap[i] = grid[i]; // Store each row vector in the row map
            vector<int> colVector(n); // Initialize a vector to store the column elements
            for (int j = 0; j < n; ++j) {
                colVector[j] = grid[j][i]; // Store each column element in the column vector
            }
            colMap[i] = colVector; // Store the column vector in the column map
        }

        int count = 0; // Initialize the count of equal pairs

        // Iterate over the rows and columns to compare them
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (rowMap[i] == colMap[j]) { // If the row and column vectors are equal
                    ++count; // Increment the count of equal pairs
                }
            }
        }

        return count; 
    
    */
}

string removeStars(string s) {

    stack<char> ch;
    string res;

    for (int i = 0; i < s.size(); i++){
        
        if(s[i] == '*'){
            ch.pop();
        }
        else{
            ch.push(s[i]);
        }
    }
    /* Reserve space for 'res' 
        By reserving space for res using res.reserve(ch.size()), you avoid potential reallocations 
        as elements are added to the string, which can improve performance, especially for large inputs*/
    res.reserve(ch.size());

    while (!ch.empty()) {
        res.push_back(ch.top());
        ch.pop();
    }

    reverse(res.begin(), res.end());

    return res;        
}

vector<int> asteroidCollision(vector<int>& asteroids) {

/* This code pass all the cases but failed during submit whie executing a case where i/p = [-2,-1,1,2]
    int as = 0;
    int res = 0;
    st.push(asteroids[0]);

    for (int i = 1; i < asteroids.size(); i++){
        as = st.top();
        if(asteroids[i] < 0){
            res = max(as,abs(asteroids[i]));
            if(res == (abs(asteroids[i]))){
                st.pop();
            }
        }

        /* We can write the upper if condition in one
        // if((asteroids[i] < 0) && (max(as,abs(asteroids[i])) == (abs(asteroids[i])))){
        //                 st.pop();
        // }
        //

        else{
            st.push(asteroids[i]);
        }
    }
*/

/* modified code from online */

    deque<int> st; // Using deque instead of stack
    vector<int> ans;
    for(int n: asteroids){
        if(n > 0){
            st.push_back(n);
        }
        else{
            while (!st.empty() && st.back() > 0 && st.back() < abs(n)) {
                st.pop_back();
            }
            if (st.empty() || st.back() < 0) {
                st.push_back(n);
            }
            else if (st.back() == abs(n)) {
                st.pop_back();
            }
        }
    }
    ans.reserve(st.size());
    for (int val : st) {
        ans.push_back(val);
    }
    return ans;   
}

//pending
string decodeString(string s) {
    stack<char> st;
    string ans;

    for(int i = 0; i < s.size(); i++){
      if(isalnum(s[i])){
          st.push(s[i]);
          cout << "top = " << st.top() << endl;
      }
    }
}

vector<int> plusOne(vector<int>& digits) {
   /* My code , failed for this:[8,9,9,9]
   vector<int> ans;
        int sum = 0, dig = 0, carry = 0;
        int size = digits.size()-1;
        sum = digits[size] + 1;
        if(sum < 10){
            cout << " in if \n";
            digits[size] = sum;
            return digits;
        }
        else{
            cout << "in else \n";
            for(int i = size; i >=0 ; i--){
                cout << "in for \n";
                dig = sum % 10;
                carry = sum / 10;
                ans.push_back(dig);
                sum = carry + digits[i];
            }
        }
        if(carry != 0){
            ans.push_back(carry);
        }
        reverse(ans.begin(),ans.end());
        return ans;
        */

       /*Optimized online code*/
        int n = digits.size();
        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] == 9) {
                digits[i] = 0; // Set current digit to 0
            } else {
                digits[i]++;   // Increment current digit
                return digits; // No carry, return the updated number
            }
        }
        // If we are here, all digits were 9
        digits.insert(digits.begin(), 1); // Insert 1 at the beginning
        return digits;
    
}

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1;
        int size = m + n - 1;

        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                // Condition: nums1[i] > nums2[j]
                nums1[size] = nums1[i]; // Set nums1[size] to nums1[i]
                cout << "if -> nums1[" << size << "] = " << nums1[i] << " (from nums1[" << i << "])" << endl;
                i--; // Decrement i
                size--; // Decrement size
            } else {
                // Condition: nums2[j] >= nums1[i]
                nums1[size] = nums2[j]; // Set nums1[size] to nums2[j]
                cout << "else -> nums1[" << size << "] = " << nums2[j] << " (from nums2[" << j << "])" << endl;
                j--; // Decrement j
                size--; // Decrement size
            }
        }

        while (j >= 0) {
            // Copy remaining elements of nums2 to nums1
            nums1[size] = nums2[j];
            cout << "while -> nums1[" << size << "] = " << nums2[j] << " (from nums2[" << j << "])" << endl;
            j--; // Decrement j
            size--; // Decrement size
        }
}

int strStr(string haystack, string needle) {

    map<int, int> occurrence;

    int i = 0, j = 0;
    int hSize = haystack.size();
    int nSize = needle.size();
    cout << "hSize = " << hSize << " and nSize = " << nSize << endl;
    int startIndex = -1;

    while (i < hSize && j < nSize) {
        if (haystack[i] == needle[j]) {
            if (startIndex == -1) {
                startIndex = i;  // Record the start index of the occurrence
            }
            j++;
            i++;
        } else {
            startIndex = -1;  // Reset start index
            i++;
            j = 0;  // Reset j if there's a mismatch
        }
    }

    for (const auto& pair : occurrence) {
        int key = pair.first;
        int value = pair.second;
        std::cout << "Key: " << key << ", Value: " << value << std::endl;
    }

    // If needle is fully matched, return the starting index
    if (j == nSize) {
        return startIndex;
    } else {
        return -1; // Needle not found
    }
}

string addBinary(string a, string b) {

    int i = a.size()-1;
    int j = b.size()-1;
    int carry = 0;

    string ans;

    while(i >= 0 && j >= 0){
        int bin = 0;
        if(a[i] == '0' && b[j] == '0'){
            bin = carry + 0;
            ans.push_back(static_cast<char>(bin+'0'));
            i--;
            j--;
            carry = 0;
        }
        else if((a[i] == '0' && b[j] == '1') || (a[i] == '1' && b[j] == '0') ){
            if(carry == 1){
                bin = 0;
                carry = 1;
                ans.push_back(static_cast<char>(bin+'0'));
                i--;
                j--;
            }
            else{
                bin = 1;
                ans.push_back(static_cast<char>(bin+'0'));
                i--;
                j--;
            }
            
        }
        else if(a[i] == '1' && b[j] == '1'){
           if(carry == 1){
                bin = 1;
                ans.push_back(static_cast<char>(bin + '0'));
                carry = 1;
                i--;
                j--;
            }
            else{
                bin = 0;
                ans.push_back(static_cast<char>(bin + '0'));
                carry = 1;
                i--;
                j--;
            }
        }
    }
    while(i >= 0){
        int bin = 0;
        if(carry == 1 && a[i] == '1'){
            bin = 0;
            ans.push_back(static_cast<char>(bin+'0'));
            carry = 1;
            i--;
        }
        else if(carry == 1 && a[i] == '0'){
            bin = 1;
            ans.push_back(static_cast<char>(bin+'0'));
            carry = 0;
            i--;
        }
        else{
            ans.push_back(a[i]);
            i--;
        }
    }
    while(j >= 0){
        int bin = 0;
        if(carry == 1 && b[j] == '1'){
            bin = 0;
            ans.push_back(static_cast<char>(bin+'0'));
            carry = 1;
            j--;
        }
        else if(carry == 1 && b[j] == '0'){
            bin = 1;
            ans.push_back(static_cast<char>(bin+'0'));
            carry = 0;
            j--;
        }
        else{
            ans.push_back(b[j]);
            j--;
        }
    }
    if (carry == 1){
        ans.push_back('1');
    }
    std::reverse(ans.begin(),ans.end());
    return ans;

/* Optimized code from online 
    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;
    string ans;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0)
            sum += a[i--] - '0';
        if (j >= 0)
            sum += b[j--] - '0';
        ans = to_string(sum % 2) +
                ans; 
        carry = sum / 2;
    }

    return ans;


*/
}

int subarraySum(vector<int>& nums, int k) {

/* This code is working fine but during submission it hit the TLE
    int count = 0;
    vector<int> prefixSum (nums.size());
    prefixSum[0] = nums[0];
    for(int i = 1; i < nums.size(); i++){
        prefixSum[i] = prefixSum[i-1] + nums[i];
    }

    // Iterate through all subarrays and count those with sum equal to k
    for(int start = 0; start < nums.size(); start++) {
        for(int end = start; end < nums.size(); end++) {
            int sum = prefixSum[end] - (start > 0 ? prefixSum[start - 1] : 0); // Calculate subarray sum
            if(sum == k) {
                count++; // Increment count if subarray sum equals k
            }
        }
    }
    return count;

*/

/* New code with uisng hash map*/

int count = 0;
unordered_map<int, int> prefixSumCount;
int prefixSum = 0;

// Add 0 as prefix sum with count 1 to handle subarrays starting from index 0
prefixSumCount[0] = 1;

for (int num : nums) {
    prefixSum += num;
    // Check if there is a prefix sum with value (prefixSum - k)
    // If found, it means there is a subarray whose sum equals k
    if (prefixSumCount.find(prefixSum - k) != prefixSumCount.end()) {
        count += prefixSumCount[prefixSum - k];
    }
    // Increment count of current prefix sum
    prefixSumCount[prefixSum]++;
}

return count;
}

int firstMissingPositive(vector<int>& nums) {

/* cod is working good but during submission it failed
    map<int,int>occ;
    vector<int> maap(100, 0);
    sort(nums.begin(),nums.end());
    // for(int n: nums){
    //     if(n >= 0){
    //         occ[n]++;
    //     }
    // }
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] >= 0){
            cout << " ffff " << endl;
            maap[nums[i]]++;
        }
    }

    for(int i = 1; i < maap.size(); i++){
        if(maap[i] == 0){
            cout << i << " ";
            return i;
        }
    }
*/

    unordered_set<int> seen(nums.begin(), nums.end());
    for (int i = 1; i <= nums.size() + 1; ++i) {
        if (!seen.count(i)) {
            return i;
        }
    }
    return -1;
}

int rob(vector<int>& nums) {
/* This solution failed for some testcases means it not covered all the cases
nums = [2,1,1,2]

Use Testcase:
Output: 3
Expected: 4

    int sum = 0, max_sum = 0;
    for(int i = 0; i < nums.size(); i++){
        sum = nums[i];
        for(int j = i+2; j < nums.size(); j = j+2){
            sum = sum + nums[j];
        }
        max_sum = max(sum,max_sum);
    }
    return max_sum;
*/

    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];

    // dp[i] represents the maximum amount of money that can be robbed up to house i
    vector<int> dp(n, 0);

    // Base cases
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < n; ++i) {
        // At each house, we have two choices:
        // 1. Rob the current house and add the loot to the money robbed from two houses ago
        // 2. Skip the current house and continue with the money robbed from the previous house
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }

    return dp[n - 1];

}

int main(){

/*
    vector<int> num = {20,100,10,12,5,13};
    
    if(increasingTriplet(num)){
        cout << "TRUE" << endl;
    }
    else{
        cout << "FALSE" << endl;
    }
    
*/

/* Add two number with LL
    ListNode *node = NULL;
    ListNode *head = node;

    ListNode *node1 = NULL;
    ListNode *head1 = node1;
    append(&head, 3);
    append(&head, 7);
    
    
    printList(head);
    cout << "\n";
    append(&head1, 9);
    append(&head1, 2);
    

    printList(head1);
    
    ListNode *ans = addTwoNumbers(head, head1);
    cout << "\nans = ";
    printList(ans);
*/
    
/* defangIPaddr
    string s = "255.100.50.0";
    string ans = defangIPaddr(s);
    cout << "score of string is: " << ans << endl;
*/   
   
/* Number of identical pair 
    Input: nums = [1,2,3,1,1,3]
    Output: 4
    Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.

   vector<int> num = {1,2,3,1,1,3};

   int ans = numIdenticalPairs(num);

   cout << "Number identical pair is: " << ans << endl;
*/

/* Increasing Triplet
    vector<int> nums = {20,100,10,12,5,13};
    if(increasingTriplet(nums)){
        cout << "TRUE" << endl;
    }
    else{
        cout << "FALSE" << endl;
    }
*/

/* numIdenticalPairs
    vector<int> nums1 = {1,2,3}; vector<int> nums2 = {2,4,6};

    vector<vector<int>> ans = findDifference(nums1, nums2);

    for (int i = 0; i < ans.size(); ++i) {
    for (int j = 0; j < ans[i].size(); ++j) {
        cout << ans[i][j] << " ";
    }
    cout << endl;
    }
*/

/* Equal Pair
    // vector<vector<int>> grid = {{3,2,1},{1,7,6},{2,7,7}};

   vector<vector<int>> grid = {{3, 1, 2, 2},{1, 4, 4, 5},{2, 4, 2, 2},{2, 4, 2, 2}};
   
   int ans = equalPairs(grid);

   cout << "Total number of eqaul pair with coloum and row: " << ans << endl;
*/
   
/* Remove stars from string

    string s = "erase*****";

    string ans = removeStars(s);

    cout << "String after removing the stars: " << ans << endl;

*/

/* Asteroids collison
    vector<int> asteroids = {-2,-1,1,2};
    vector<int> ans = asteroidCollision(asteroids);
    for (auto count: ans){
        cout << count << " ";
    }
*/

/* Decode String
    string s = "3[a]2[bc]";
    string ans = decodeString(s);
    
    cout << "Decoded string is: " << ans << endl;
*/       
    
/* Plus one   
    vector<int> digits = {9,9,9};
    vector<int> ans = plusOne(digits); 

    for (auto count: ans){
        cout << count << " ";
    }
*/

/* Merge sorted array
    vector<int> nums1 = {1,2,3,0,0,0}; vector<int> nums2 = {2,5,6};
    int n = 3, m = 3;
    merge(nums1, m, nums2, n);
     for (auto count: nums1){
        cout << count << " ";
    }
*/

/* Get the first occurence of string
    Input: haystack = "sadbutsad", needle = "sad"
    Output: 0 

    string haystack = "mississippi";
    string needle = "issip";

    int ans = strStr(haystack, needle);

    cout << "first occurrence of string is at = " << ans << endl;
*/
   
/* add the binary
    string a = "1111", b = "1111";
    string ans = addBinary(a, b);
    cout << "ans = " << ans << endl;

*/

/* Sub array sum 
    vector<int>nums = {1,1,1};
    int k = 2;
    int ans = subarraySum(nums, k);

    cout << "ans = " << ans << endl;
*/
    
/* first missing positive number 
    vector<int> nums = {3,4,-1,1};
    int ans = firstMissingPositive(nums);
    cout << "ans = " << ans << endl;
*/
    
/* Rob the house */    
    vector<int> nums = {2,1,1,2};
    int ans = rob(nums);
    cout << "Rob amount = " << ans << endl;
    /* 
    for (auto count: ans){
        cout << count << " ";
    }*/
    return 0;

}



/*
#include <iostream>
#include <string>
using namespace std;

string mergeStrings(string word1, string word2) {
    string merged;
    int i = 0, j = 0;

    while (i < word1.size() && j < word2.size()) {
        merged += word1[i++];
        //rged += ' '; // Insert space between characters
        merged += word2[j++];
    }

    while (i < word1.size()) {
        merged += word1[i++];
        merged += ' ';
        
    }

    while (j < word2.size()) {
        merged += ' '; // Insert space before appending characters from word2
        merged += word2[j++];
    }

    return merged;
}

int main() {
    string word1 = "ab";
    string word2 = "pqrs";
    string merged = mergeStrings(word1, word2);
    cout << "Merged string: " << merged << endl;
    return 0;
}


}




*/