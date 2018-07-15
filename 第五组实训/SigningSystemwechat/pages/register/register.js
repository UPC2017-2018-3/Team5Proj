Page({
  data: {
    latitude: 23.099994,
    longitude: 113.324520,
    markers: [],
    circles: [],
    adress: '',
    range:['运行中','已到截止时间','关停签到'],
    isCreator:false,
    name:'',
    aId:'',
  },
  onReady: function (e) {
    this.mapCtx = wx.createMapContext('registerMap');
    let self = this;
  },
  onLoad:function(){
    let self=this;
    wx.getLocation({
      success: function(res) {
        self.setData({
          latitude:res.latitude,
          longitude:res.longitude
        });
      },
    });
    let appData=getApp().globalData;
    this.setData({
      isCreator:appData.openid===appData.cId?true:false,
      name:appData.name,
      aId:appData.aId,
      description:appData.description,
      markers: [{
        id: 1,
        latitude: appData.latitude,
        longitude: appData.longitude,
        label: {
          content: '签到人数：' + appData.num,
          bgColor: '#FFFFFF',
          color: '#000000',
          fontSize: 10,
          display: 'ALWAYS',
          x: -35,
          y: -70,
          padding: 5
        },
        iconPath: '/image/location.png',
      }],
      circles: [{
        latitude: appData.latitude,
        longitude: appData.longitude,
        color: '#7cb5ec88',
        fillColor: '#7cb5ec88',
        radius: appData.distance
      }],
    });
  },
  signIn:function(){
    let appData=getApp().globalData;
    let self=this;
    wx.request({
      url: appData.host +'/Controller/createRecord',
      data:{
        aId:appData.aId,
        avatar:appData.avatar,
        latitude: self.data.latitude,
        longitude: self.data.longitude,
        sId: appData.openid,
        sName:appData.nickName,
      },
      header: {
        'content-type': 'application/json' // 默认值
      },
      method: 'POST',
      success:function(res){
        console.log(res);
        if(res.data===false){
          wx.showToast({
            title: '您已签过到了或您处于无法签到的状态(距离过大或活动关闭)',
            icon:'none',
            duration:3000
          });
          return;
        }
        appData.num++;
        console.log(res);
        console.log(appData.num);
        self.setData({
          markers: [{
            id: 1,
            latitude: appData.latitude,
            longitude: appData.longitude,
            label: {
              content: '签到人数：' + appData.num,
              bgColor: '#FFFFFF',
              color: '#000000',
              fontSize: 10,
              display: 'ALWAYS',
              x: -40,
              y: -70,
              padding: 5
            },
            iconPath: '/image/location.png'
          }],
        });
        wx.showToast({
          title: '签到成功',
        });
      }
    })
  },
  showSigners:function(){
    wx.navigateTo({
      url: '/pages/signers/signers',
    })
  },
  showInform:function(){
    wx.showModal({
      title: this.data.name,
      content: this.data.aId+'#'+this.data.description,
      showCancel:false,
    })
  },
  setState:function(e){
    let appData=getApp().globalData;
    wx.request({
      url: appData.host + '/Controller/updateActivityState?aId=' + appData.aId + '&state=' + (parseInt(e.detail.value)+1),
      success:function(res){
        console.log(res);
        if(res.data===true){
          wx.showToast({
            title: '修改成功',
          })
        }else{
          wx.showToast({
            title: '出现异常啦┭┮﹏┭┮',
            icon:'none'
          })
        }
      }
    })
  }
})
