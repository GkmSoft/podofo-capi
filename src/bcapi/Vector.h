/***************************************************************************
 *   Copyright (C) 2006 by Dominik Seichter                                *
 *   domseichter@web.de                                                    *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU Library General Public License as       *
 *   published by the Free Software Foundation; either version 2 of the    *
 *   License, or (at your option) any later version.                       *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU Library General Public     *
 *   License along with this program; if not, write to the                 *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 *                                                                         *
 *   In addition, as a special exception, the copyright holders give       *
 *   permission to link the code of portions of this program with the      *
 *   OpenSSL library under certain conditions as described in each         *
 *   individual source file, and distribute linked combinations            *
 *   including the two.                                                    *
 *   You must obey the GNU General Public License in all respects          *
 *   for all of the code used other than OpenSSL.  If you modify           *
 *   file(s) with this exception, you may extend this exception to your    *
 *   version of the file(s), but you are not obligated to do so.  If you   *
 *   do not wish to do so, delete this exception statement from your       *
 *   version.  If you delete this exception statement from all source      *
 *   files in the program, then also delete it here.                       *
 ***************************************************************************/

#include <vector>

#include "boost/shared_ptr.hpp"
#include "boost/make_shared.hpp"

namespace Bcapi{
    
    template < template <class T> class Ptr> 
    class Vector
    {
        std::vector<Ptr<class T> > mVector;
    public:
        Vector(std::vector<class Ptr<class T> >&& std_vector)
        {
            mVector = std_vector;  
        }

        Vector(std::vector<class Ptr<class T>*>&& std_vector)
        {
            mVector = new std::vector<boost::shared_ptr<class T> >;
            for (auto it = (*std_vector).begin(); it != (*std_vector).end(); it++)
                mVector.insert(boost::shared_ptr<class T>(boost::make_shared<class T>(*it))); 
        }

        Vector(std::vector<class Ptr<class T*>*>&& std_vector)
        {
            mVector = new std::vector<boost::shared_ptr<class T> >;
            for (auto it = (*std_vector).begin(); it != (*std_vector).end(); it++)
                mVector.insert(boost::shared_ptr<class T>(boost::make_shared<class T>(**it))); 
        }

        size_t GetSize() const
        {
            return mVector.size();
        }

        std::vector<class T>& GetStdVector()
        {
            std::vector<class T>* std_vector = new std::vector<class T>;
            for (auto it = mVector.begin(); it != mVector.end(); it++)            
                std_vector->insert((*it)->get());          
            return *std_vector;
        }

        template <class T> 
        Vector(std::vector<T>&& std_vector)
        {
            mVector = new std::vector<boost::shared_ptr<T> >;
            for (auto it = std_vector.begin(); it != std_vector.end(); it++)
                std_vector.insert(boost::shared_ptr<T>(boost::make_shared<T>(*it)));   
        }

        template <class T> 
        Vector(std::vector<T*>&& std_vector)
        {
            mVector = new std::vector<boost::shared_ptr<T> >;
            for (auto it = std_vector.begin(); it != std_vector.end(); it++)
                std_vector.insert(boost::shared_ptr<T>(boost::make_shared<T>(*it)));   
        }
    };
    
    /*
    template <typename Object> 
    class Vector
    {
        std::vector<boost::shared_ptr<Object> > mVector;
    public:
        Vector(std::vector<Object>&& std_vector)
        {
            mVector = new std::vector<boost::shared_ptr<Object> >;
            for (auto it = std_vector.begin(); it != std_vector.end(); it++)
                if (!std::is_same(<boost::shared_ptr<typename>, *it>::value))
            std_vector.insert(boost::shared_ptr<Object>(boost::make_shared<Object>(*it)));   
        }
        
        size_t GetSize() const
        {
            return mVector.size();
        }

        std::vector<Object>&& GetStdVector()
        {
            std::vector<Object> result;
            for (auto it = mVector.begin(); it != mVector.end(); it++)            
                result.insert((*it)->get());          
            return result;
        }
   };
    */
}
