Page({
  data: {
    latitude: 23.099994,
    longitude: 113.324520,
    markers: [],
    circles:[],
    adress:'',
  },
  onReady: function (e) {
    this.mapCtx = wx.createMapContext('myMap');
    let self=this;
    wx.getLocation({
      type: 'gcj02', //返回可以用于wx.openLocation的经纬度
      success: function(res) {
        self.setData({
          latitude:res.latitude,
          longitude: res.longitude,
          markers: [{
            id: 1,
            latitude: res.latitude,
            longitude: res.longitude,
            label: {
              content: '进入范围方可签到',
              bgColor: '#FFFFFF',
              color:'#000000',
              fontSize: 10,
              display: 'ALWAYS',
              x: -47,
              y: -70,
              padding: 5
            },
            iconPath: '/image/location.png'
          }],
          circles: [{
            latitude: res.latitude,
            longitude: res.longitude,
            color: '#7cb5ec88',
            fillColor: '#7cb5ec88',
            radius: 200
          }],
        });
      },
    })
  },
  changeCenter:function(){
    let self=this;
    self.mapCtx.getCenterLocation({
      success:function(res){
        self.setData({
          markers: [{
            id: 1,
            latitude: res.latitude,
            longitude: res.longitude,
            label: {
              content: '进入范围方可签到',
              bgColor: '#FFFFFF',
              color: '#000000',
              fontSize: 10,
              display: 'ALWAYS',
              x:-47,
              y:-70,
              padding:5
            },
            iconPath: '/image/location.png'
          }],
          circles: [{
            latitude: res.latitude,
            longitude: res.longitude,
            color: '#7cb5ec88',
            fillColor: '#7cb5ec88',
            radius: 200
          }],
        });
      }
    });
  },
  edit:function(){
    let self=this;
    wx.navigateTo({
      url: '/pages/edit/edit?latitude=' + self.data.latitude + '&longitude=' + self.data.longitude,
    })
  },
  showRecord:function(){
    wx.navigateTo({
      url: '/pages/records/records?type=1',
    });
  },
  search:function(e){
    let keywords = e.detail.value.keywords;
    wx.navigateTo({
      url: '/pages/records/records?type=0&keywords=' + keywords,
    })
  },
  getUserInfo:function(e){
    let appData=getApp().globalData;
    let info=e.detail.userInfo;
    appData.nickName=info.nickName;
    appData.avatar=info.avatarUrl;
    appData.gender = info.gender === 1 ? '男' : '女';
    console.log(appData);
  }
})
