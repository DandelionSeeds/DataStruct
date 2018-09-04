#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;


void childStrFuc(string sample, int lenth, vector<string>middleVec, vector<string>&resultVec)
{
	vector<string> middleVecCopy = middleVec;
	middleVec.clear();

	if (middleVecCopy.empty())
	{
		for (int i = 0; i < sample.size(); i++)
		{
			string str;
			str.push_back(sample.at(i));
			middleVecCopy.push_back(str);
		}
		childStrFuc(sample, lenth, middleVecCopy, resultVec);
	}
	else
	{
		for (int j = 0; j < middleVecCopy.size(); j++)
		{
			if (middleVecCopy.at(j).size() < lenth)
			{
				for (int k = 0; k < sample.size(); k++)
				{
					if (sample.at(k) > middleVecCopy.at(j).back())
					{
						string combinStr = middleVecCopy.at(j);
						combinStr = combinStr + sample.at(k);
						middleVec.push_back(combinStr);
					}
				}
			}
			else
			{
				resultVec.push_back(middleVecCopy.at(j));
			}
		}
		if (resultVec.size() != middleVecCopy.size())
		{
			childStrFuc(sample, lenth, middleVec, resultVec);
		}
	}
}

int main()
{
	vector<string>middleVec; 
	vector<string>resultVec;
	childStrFuc("abcde", 4, middleVec, resultVec);
}