
App({
  //47.100.111.185
  globalData:{
    host:'http://47.100.111.185:8088',
    appid: 'wx3481496e66037c43',
    secret: 'aebf39205d9f6c1ed2328ea7ee65fc00',
    openid:'',
    nickName:'',
    avatar:'',
    aId:'',
    cId:'',
    latitude:'',
    longitude:'',
    num:0,
    distance:200,
    name:'',
    description:'',
  },
  onLaunch: function () {
    var that = this
    var user = wx.getStorageSync('user') || {};
    var userInfo = wx.getStorageSync('userInfo') || {};
    if ((!user.openid || (user.expires_in || Date.now()) < (Date.now() + 600)) && (!userInfo.nickName)) {
      wx.login({
        success: function (res) {
          console.log(res);
          if (res.code) {
            var d = that.globalData;//这里存储了appid、secret、token串  
            var l = 'https://api.weixin.qq.com/sns/jscode2session?appid=' + d.appid + '&secret=' + d.secret + '&js_code=' + res.code + '&grant_type=authorization_code';
            wx.request({
              url: l,
              data: {},
              method: 'GET', // OPTIONS, GET, HEAD, POST, PUT, DELETE, TRACE, CONNECT  
              // header: {}, // 设置请求的 header  
              success: function (res) {
                var obj = {};
                obj.openid = res.data.openid;
                d.openid=obj.openid;
                obj.expires_in = Date.now() + res.data.expires_in;
                wx.setStorageSync('user', obj);//存储openid  
              }
            });
          } else {
            console.log('获取用户登录态失败！' + res.errMsg)
          }
        }
      });
    } 
  }
})
