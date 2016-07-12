private void check()
{
    int[] numArray;
    bool flag;
    int num;
    int[] numArray2;
    string str;
    int num2;
    if (Array.IndexOf<bool>(this.state, 1) >= 0)
    {
        goto Label_009F;
    }
    MessageBox.Show("Congratulations!");
    numArray = new int[] { 1, 7, 0x10, 11, 14, 0x13, 20, 0x12 };
    flag = 1;
    num = 0;
    goto Label_0048;
Label_0035:
    if (this.hist[num] == numArray[num])
    {
        goto Label_0044;
    }
    flag = 0;
Label_0044:
    num += 1;
Label_0048:
    if (num < 8)
    {
        goto Label_0035;
    }
    if (flag == null)
    {
        goto Label_009F;
    }
    numArray2 = new int[] { 
        0x55, 0x6f, 0x75, 0x2b, 0x68, 0x7f, 0x75, 0x75, 0x21, 110, 0x63, 0x2b, 0x48, 0x5f, 0x55, 0x55,
        0x5e, 0x42, 120, 0x62, 0x4f, 0x75, 0x44, 0x53, 0x40, 0x5e, 0x27, 0x41, 0x49, 0x20, 0x41, 0x48,
        0x33
    };
    str = "";
    num2 = 0;
    goto Label_0090;
Label_006E:
    str = str + ((char) ((ushort) (numArray2[num2] ^ numArray[num2 % ((int) numArray.Length)])));
    num2 += 1;
Label_0090:
    if (num2 < ((int) numArray2.Length))
    {
        goto Label_006E;
    }
    MessageBox.Show(str);
Label_009F:
    return;
}

 

 
 85 0x55private void check()
{
    int[] numArray;
    bool flag;
    int num;
    int[] numArray2;
    string str;
    int num2;
    if (Array.IndexOf<bool>(this.state, 1) >= 0)
    {
        goto Label_009F;
    }
    MessageBox.Show("Congratulations!");
    numArray = new int[] { 1, 7, 0x10, 11, 14, 0x13, 20, 0x12 };
    flag = 1;
    num = 0;
    goto Label_0048;
Label_0035:
    if (this.hist[num] == numArray[num])
    {
        goto Label_0044;
    }
    flag = 0;
Label_0044:
    num += 1;
Label_0048:
    if (num < 8)
    {
        goto Label_0035;
    }
    if (flag == null)
    {
        goto Label_009F;
    }
    numArray2 = new int[] { 
        0x55, 0x6f, 0x75, 0x2b, 0x68, 0x7f, 0x75, 0x75, 0x21, 110, 0x63, 0x2b, 0x48, 0x5f, 0x55, 0x55,
        0x5e, 0x42, 120, 0x62, 0x4f, 0x75, 0x44, 0x53, 0x40, 0x5e, 0x27, 0x41, 0x49, 0x20, 0x41, 0x48,
        0x33
    };
    str = "";
    num2 = 0;
    goto Label_0090;
Label_006E:
    str = str + ((char) ((ushort) (numArray2[num2] ^ numArray[num2 % ((int) numArray.Length)])));
    num2 += 1;
Label_0090:
    if (num2 < ((int) numArray2.Length))
    {
        goto Label_006E;
    }
    MessageBox.Show(str);
Label_009F:
    return;
}

 
