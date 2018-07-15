// pages/edit/edit.js
Page({

  /**
   * 页面的初始数据
   */
  data: {
    startDay:'开始日期',
    startTime:'开始时间',
    endDay:'结束日期',
    endTime:'结束时间',
    address:'选择地址',
    latitude: 1,
    longitude: 1,
  },

  /**
   * 生命周期函数--监听页面加载
   */
  onLoad: function (options) {
    this.setData({
      latitude: options.latitude,
      longitude: options.longitude
    });
  },
  formSubmit:function(e){
    let value=e.detail.value;
    let data=this.data;
    let dateObj=new Date();
    //let date = dateObj.getFullYear() + '-' + (dateObj.getMonth()+1)+'-'+dateObj.getDate();
    let appData=getApp().globalData;
    wx.request({
      url: getApp().globalData.host +'/Controller/createActivity', 
      data: {
        aName:value.name,
        description:value.description,
        start:data.startDay+'T'+data.startTime+':00.000Z',
        end: data.endDay + 'T' + data.endTime + ':00.000Z',
        latitude: data.latitude,
        longitude: data.longitude,
        site:data.address,
        cId: appData.openid,
        avatar:appData.avatar,
        cName:appData.nickName,
        distance:value.distance
      },
      header: {
        'content-type': 'application/json' // 默认值
      },
      method: 'POST',
      success: function (res) {
        console.log(res.data);
        if(res.data===false){
          wx.showToast({
            title: '发布失败',
            icon:'none'
          });
          return;
        }
        appData.latitude=data.latitude;
        appData.longitude = data.longitude;
        appData.aId=res.data;
        appData.distance = parseInt(value.distance);
        appData.num=0;
        appData.name = value.name;
        appData.description = value.description;
        appData.cId=appData.openid;
        wx.navigateTo({
          url: '/pages/register/register',
        });
      }
    })
  },
  startDayChange:function(e){
    this.setData({
      startDay:e.detail.value
    });
  },
  startTimeChange:function(e){
    this.setData({
      startTime:e.detail.value
    });
  } ,
  endDayChange: function (e) {
    this.setData({
      endDay: e.detail.value
    });
  },
  endTimeChange:function(e){
    this.setData({
      endTime:e.detail.value
    });
  },
  chooseLocation:function(){
    let self=this;
    wx.chooseLocation({
      success: function(res) {
        if(res.address!==undefined){
          self.setData({
            address:res.address,
            latitude: res.latitude,
            longitude: res.longitude,
          });
        }
      },
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
  
  },
})