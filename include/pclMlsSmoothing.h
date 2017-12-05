// "Copyright [2017] <Michael Kam>"
/** @file pclMlsSmoothing.h
 *  @brief header file of an pclMlsSmoothing class
 *
 *  This class utilizes pcl moving least square(mls) method to
 *  smooth the point cloud among the surface.
 *
 *  @author Michael Kam (michael081906)
 *  @bug No known bugs.
 *  @copyright GNU Public License.
 */

#ifndef INCLUDE_PCLMLSSMOOTHING_H_
#define INCLUDE_PCLMLSSMOOTHING_H_
#include <pcl/io/io.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/surface/mls.h>
#include <iostream>
#include <vector>
#include <ios>
// using namespace pcl;
/** @brief pclMlsSmoothing is an implementation by using moving least square(mls) method
 *  to smooth the point cloud among the surface.
 *
 *  @author Michael Kam (michael081906)
 *  @bug No known bugs.
 *  @copyright GNU Public License.
 */
class pclMlsSmoothing {
 private:
  /**@brief object of PointXYZ */
  pcl::PointCloud<pcl::PointXYZ> cloud;
  /**@brief shared pointer in which data type is PointXYZ  */
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloudPtr;
  /**@brief search range when computing the mls */
  double searchRadius;

 public:
  /**@brief constructor */
  pclMlsSmoothing();
  /**@brief set a search range into searchRadius variable
   * @param[in] radius range of choosing
   * @return none */
  void setSearchRadius(double radius);
  /**@brief get a search range from searchRadius variable
   * @return search range  */
  double getSearchRadius();
  /**@brief input a point cloud data and set it to the private cloud
   * @param[in] cloudIn reference of a point cloud
   * @return none */
  void setInputCloud(const pcl::PointCloud<pcl::PointXYZ>& cloudIn);
  /**@brief get a point cloud data from private cloud
   * @param[in] cloudOut reference of a point cloud
   * @return none */
  void getInputCloud(pcl::PointCloud<pcl::PointXYZ>& cloudOut);
  /**@brief compute the mls method to smooth the point cloud
   * @param[in] cloudOut reference of a point cloud
   * @return none */
  void mlsProcess(pcl::PointCloud<pcl::PointNormal>& cloudOut);
};
#endif  // INCLUDE_PCLMLSSMOOTHING_H_
