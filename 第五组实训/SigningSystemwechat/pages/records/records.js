// pages/record/record.js
Page({

  /**
   * 页面的初始数据
   */
  data: {
    records:[],
    type:'0'
  },

  /**
   * 生命周期函数--监听页面加载
   */
  onLoad: function (options) {
    let self=this;
    let appData=getApp().globalData;
    console.log(options.type);
    let records = [];
    if(options.type==='0'){
      wx.request({
        url: appData.host +'/Controller/findActivities?str='+options.keywords,
        success:function(res){
          console.log(res);
          self.setData({
            records: res.data
          });
        }
      })
    }else{
      wx.request({
        url: appData.host +'/Controller/findActivitiesByCId?cId='+appData.openid,
        success:function(res){
          console.log(res);
          self.setData({
            records: res.data
          });
        }
      })
    }
    this.setData({
      type:options.type
    });
  },
  showActivity:function(e){
    let record = this.data.records[e.currentTarget.dataset.index];
    console.log(record);
    let appData=getApp().globalData;
    appData.latitude = record.latitude;
    appData.longitude = record.longitude;
    appData.num = record.number;
    appData.distance = record.distance !== undefined ? record.distance:200;
    appData.aId=record.aId;
    appData.cId=record.cId;
    appData.name=record.aName;
    appData.description=record.description;
    wx.navigateTo({
      url: '/pages/register/register?record='+record,
    })
  },
  deleteActivity:function(e){
    if(this.data.type==='0')
      return;
    let self=this;
    let records = this.data.records;
    let index = e.currentTarget.dataset.index;//获取当前长按图片下标
    let appData=getApp().globalData;
    wx.showModal({
      title: '提示',
      content: '确定要删除此活动？',
      success: function (res) {
        if (res.confirm) {
          console.log('点击确定了');
          wx.request({
            url: appData.host +'/Controller/deleteActivity?aId='+records[index].aId,
            success:function(res){
              console.log(res);
              if(res.data===true){
                records.splice(index, 1);
                self.setData({
                  records:records
                });
              }else
              wx.showToast({
                title: 'mygod，删除失败了',
                icon:'none'
              })
            }
          })
        } else if (res.cancel) {
          console.log('点击取消了');
          return false;
        }
      }
    })
  },

  /**
   * 生命周期函数--监听页面初次渲染完成
   */
  onReady: function () {
  
  },

  /**
   * 生命周期函数--监听页面显示
   */
  onShow: function () {
  
  },

  /**
   * 生命周期函数--监听页面隐藏
   */
  onHide: function () {
  
  },

  /**
   * 生命周期函数--监听页面卸载
   */
  onUnload: function () {
  
  },

  /**
   * 页面相关事件处理函数--监听用户下拉动作
   */
  onPullDownRefresh: function () {
  
  },

  /**
   * 页面上拉触底事件的处理函数
   */
  onReachBottom: function () {
  
  },

  /**
   * 用户点击右上角分享
   */
  onShareAppMessage: function () {
  
  }
})