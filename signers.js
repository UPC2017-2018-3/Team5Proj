// pages/signers/signers.js
Page({

  /**
   * 页面的初始数据
   */
  data: {
    signers:[],
  },

  /**
   * 生命周期函数--监听页面加载
   */
  onLoad: function (options) {
    let appData = getApp().globalData;
    let self = this;
    wx.request({
      url: appData.host + '/Controller/findRecordsByAId?aId=' + appData.aId,
      success: function (res) {
        console.log(res);
        let data=res.data;
        let l=data.length;
        let signers=[];
        for (let i=0;i<l;i++) {
          signers[i]={
            id:i,
            src:data[i].avatar,
            name:data[i].sName,
            time:data[i].time,
            bgcolor: data[i].type === 1 ? '#FFFFFF' :'#FFFFCC'
          }
        }
        self.setData({
          signers:signers
        });
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