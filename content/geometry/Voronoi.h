/**
 * Author:
 * Date:
 * License:
 * Source: 
 * Description:
 * Status: 
 */

#include "ConvexHull.h"
#include "lineIntersection.h"

vector<vector<P> > voronoi(const vector<P>& inp)
{
	vector<P> poly = inp;
	vector<vector<P>> res;
	vector<PP> inv;
	vector<pair<P,P>> ans;
	vector<PP> vor;
	vector<P> V;
	int n = poly.size();
	poly.push_back(P());
	poly.push_back(P());
	poly.push_back(P());
	poly.push_back(P());
	for (int i=0; i<n; i++)
	{
		poly[n] = P(-2*oo-poly[i].x,poly[i].y);
		poly[n+1] = (P(poly[i].x,2*oo-poly[i].y));
		poly[n+2] = (P(2*oo-poly[i].x,poly[i].y));
		poly[n+3] = (P(poly[i].x,-2*oo-poly[i].y));
		inv.clear();
		for (int j=0; j<n+4; j++)
		if (j!=i)
		{
			//int jj = j - (j>i);
			double tmp = (poly[j]-poly[i]).dist2();
			inv.push_back(make_pair((poly[j]-poly[i])/tmp,j));
			//cerr << inv[inv.size()-1].first << '\n';
		}
		vor = convexHull(inv);
		vor.push_back(*vor.begin());
		int vors = vor.size();
		ans.clear();
		for (int j=0; j<vors; j++)
		{
			P tmp = (poly[i]+poly[vor[j].second])/2.0;
			ans.push_back(make_pair(tmp,P(tmp.x-(poly[vor[j].second].y-poly[i].y),tmp.y+(poly[vor[j].second].x-poly[i].x))));
		} 
		V.clear();
		for (int j=1; j<vors; j++)
		{
			pair<int,P> v = lineInter(ans[j-1].first,ans[j-1].second,ans[j].first,ans[j].second);
			V.push_back(v.second);
		}
		res.push_back(V);
	} 
	return res;
}
