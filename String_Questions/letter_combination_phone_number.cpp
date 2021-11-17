class Solution
{
public:
    string getString(int c)
    {
        if (c == 2)
        {
            return "abc";
        }
        if (c == 3)
        {
            return "def";
        }
        if (c == 4)
        {
            return "ghi";
        }
        if (c == 5)
        {
            return "jkl";
        }
        if (c == 6)
        {
            return "mno";
        }
        if (c == 7)
        {
            return "pqrs";
        }
        if (c == 8)
        {
            return "tuv";
        }
        if (c == 9)
        {
            return "wxyz";
        }
        return " ";
    }

    int KeyPadCombinations(int digits, string output[])
    {

        if (digits == 0)
        {
            output[0] = "";
            return 1;
        }

        int last_digit = digits % 10;
        int small_number = digits / 10;

        //For the small number it will fill the output array
        int small_output_size = KeyPadCombinations(small_number, output);

        string options = getString(last_digit);

        //For creating the copies of the array - equal to the option length
        for (int i = 0; i < options.length() - 1; i++)
        {

            for (int j = 0; j < small_output_size; j++)
            {
                output[j + (i + 1) * small_output_size] = output[j];
            }
        }

        //After creating the copy appending the options one by one to the small output size
        int k = 0;
        for (int j = 0; j < options.length(); j++)
        {
            for (int i = 0; i < small_output_size; i++)
            {
                output[k] = output[k] + options[j];
                k++;
            }
        }

        return options.length() * small_output_size;
    }

    vector<string> letterCombinations(string digits)
    {

        string output[10000];
        vector<string> arr;
        int num;

        if (digits.empty())
        {
            return arr;
        }

        // using stoi() to store the value of str1 to x
        num = std::stoi(digits);
        cout << num << endl;
        int count = KeyPadCombinations(num, output);

        for (int i = 0; i < count; i++)
        {
            arr.push_back(output[i]);
            //cout<<output[i]<<endl;
        }

        return arr;
    }
};