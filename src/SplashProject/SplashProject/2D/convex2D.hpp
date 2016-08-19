// Splash (c) - open-source C++ library for geometry and linear algebra.
// Copyright (c) 2016, Ilya Zakharkin, Elena Kirilenko and Nadezhda Kasimova.
// All rights reserved.
/*
	This file is part of Splash.

	Splash is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	Splash is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with Splash. If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef CONVEX2D_HPP_
#define CONVEX2D_HPP_

#include "../splash_forward.hpp"
#include "../splash_utils.hpp"

#include "point2D.hpp"
#include "vector2D.hpp"
#include "line2D.hpp"
#include "segment2D.hpp"
#include "polygon.hpp"

class Convex2D : public Polygon
{
public:
	Convex2D();
	Convex2D(int n);
	// copying
	Convex2D(const Convex2D& second_polygon);
	void operator =(const Convex2D& second_polygon);
	// moving
	Convex2D(Convex2D&& second_polygon);
	void operator =(Convex2D&& second_polygon);

	Convex2D(const vector<Point2D>& points);
	void operator =(const vector<Point2D>& points);

	void AddVertex(const Point2D& new_vertex);

	int Size() const;

	Point2D Next(int i) const;
	Point2D Prev(int i) const;
	Point2D GetCurVertex() const;
	void MoveCurVertex();
	Segment2D GetCurEdge() const;

	vector<Point2D> GetVertices() const;
	vector<Segment2D> GetEdges() const;

	Convex2D MakeConvexHullGrehem(const vector<Point2D>& points);
	Convex2D MakeConvexHullJarvis(const vector<Point2D>& points);

	double Area() const;
	bool Contains(const Point2D&) const;
	bool Boundary(const Point2D&) const;
	bool Intersect(const Segment2D&, Point2D&, Point2D&) const; // TODO

	vector<Point2D> GetIntersection(const Segment2D& segment) const;
	Convex2D GetIntersectionalConvex(Convex2D& second_polygon);
private:
	int cur_vertex_ind;
};

#endif /*CONVEX2D_HPP_*/