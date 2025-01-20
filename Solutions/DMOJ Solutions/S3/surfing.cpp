#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://dmoj.ca/problem/ccc00s3
  Points: 20/20
******************************************/

void surfing()
{
  int numberOfWebPages;
  cin >> numberOfWebPages;

  string link;
  string line;

  getline(cin, link);
  unordered_map<string, vector<string>> linksMap;
  vector<pair<string, string>> orderedLinks;
  for (int i = 0; i < numberOfWebPages; ++i)
  {
    getline(cin, link);

    int res = 0;
    while (true)
    {
      getline(cin, line);
      while ((res = line.find("HREF", res + 1)) != string::npos)
      {
        string hyperlink = "";
        int j = res + 6;
        while (line[j] != '"')
        {
          hyperlink += line[j];
          ++j;
        }
        linksMap[link].push_back(hyperlink);
        orderedLinks.push_back(pair<string, string>(link, hyperlink));
      }

      if (line.find("</HTML>") != string::npos)
        break;
    }
  }

  string startLink;
  string endLink;

  getline(cin, startLink);
  getline(cin, endLink);
  vector<string> results;
  while (startLink != "The End")
  {
    queue<string> nextUrls;
    set<string> visited;
    bool canSurf = false;

    nextUrls.push(startLink);
    while (!nextUrls.empty())
    {
      string url = nextUrls.front();
      nextUrls.pop();
      if (visited.count(url) > 0)
        continue;
      visited.insert(url);

      if (url == endLink)
      {
        results.push_back("Can surf from " + startLink + " to " + endLink + ".");
        canSurf = true;
        break;
      }

      for (auto neighbour : linksMap[url])
        nextUrls.push(neighbour);
    }

    if (canSurf == false)
      results.push_back("Can't surf from " + startLink + " to " + endLink + ".");

    getline(cin, startLink);
    if (startLink == "The End")
      break;
    getline(cin, endLink);
  }

  for (int i = 0; i < orderedLinks.size(); ++i)
    cout << "Link from " << orderedLinks[i].first << " to " << orderedLinks[i].second << "\n";

  for (auto result : results)
    cout << result << "\n";
}

int main()
{
  surfing();
  return 0;
}