#include "../../../helperFunctions.h"

using namespace std;

/******************************************
  Link: https://leetcode.com/problems/simplify-path/description/
  Runtime: 100.00%
  Memory: 85.20%
******************************************/

string simplifyPath(string path)
{
  string result = "";
  deque<string> directories;

  for (int i = 0; i < path.size(); ++i)
  {
    if (path[i] == '/')
      continue;

    if (path[i] == '.')
    {
      string nextLetters = "";
      for (; i < path.size(); ++i)
      {
        if (path[i] == '/')
          break;
        nextLetters += path[i];
      }
      // It is ".." so go back a directory
      if (nextLetters == ".." && !directories.empty())
        directories.pop_back();
      else if (nextLetters != ".." && nextLetters != ".")
        directories.push_back(nextLetters);
    }
    else
    {
      string directoryName = "";
      for (; i < path.size(); ++i)
      {
        if (path[i] == '/')
          break;
        directoryName += path[i];
      }
      directories.push_back(directoryName);
    }
  }

  while (!directories.empty())
  {
    result += "/" + directories.front();
    directories.pop_front();
  }
  return result.size() == 0 ? "/" : result;
}

int main()
{
  cout << simplifyPath("/../..ga/b/.f..d/..../e.baaeeh./.a") << endl;
  return 0;
}