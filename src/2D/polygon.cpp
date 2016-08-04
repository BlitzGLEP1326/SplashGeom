// Splash (c) - open-source C++ library for geometry and linear algebra
// Copyright (c) 2016, Ilya Zakharkin, Elena Kirilenko and Nadezhda Kasimova.
// All rights reserved.
/*
This file is part of Splash.

Splash is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Foobar is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "polygon.hpp"

Polygon::Polygon()
	: vertices_(0) {}

Polygon::Polygon(int n)
	: vertices_(n) {}

Polygon::Polygon(const vector<Point2D>& points)
{
	for (size_t i = 0; i < points.size(); ++i)
		vertices_.push_back(points[i]);
	//std::copy(points.begin(), points.end(), vertices_.begin());
}

void Polygon::operator = (const vector<Point2D>& points)
{
	for (size_t i = 0; i < points.size(); ++i)
		vertices_.push_back(points[i]);
	//std::copy(points.begin(), points.end(), vertices_.begin());
}


double Polygon::Area() const
{
	double area = 0;
	int num_of_vertices = vertices_.size();

	for (int i = 0; i < num_of_vertices; ++i)
	{
		int j = (i + 1) % num_of_vertices;
		area += Vector2D(vertices_[i]).OrientedCCW(Vector2D(vertices_[j] - vertices_[i]));
	}

	return fabs(area / 2.0);
}

bool Polygon::Contains(const Point2D& point) const
{
	return 0;
}

bool Polygon::Boundary(const Point2D & p) const
{
	return 0;
}

bool Polygon::Intersect(const Segment2D& seg, Point2D& p1, Point2D& p2) const
{
	return 0;
}