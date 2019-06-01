import Vue from 'vue'
import App from './App.vue'
import Bootstrap from 'bootstrap/dist/css/bootstrap.min.css'
import firebase from 'firebase'

Vue.config.productionTip = false
const firebaseConfig = {
  apiKey: "AIzaSyBhOSto56sDINFnDZM3Xw41Dngp5cPRtz4",
  authDomain: "namiixz.firebaseapp.com",
  databaseURL: "https://namiixz.firebaseio.com",
  projectId: "namiixz",
  storageBucket: "namiixz.appspot.com",
  messagingSenderId: "519212122794",
  appId: "1:519212122794:web:eb5678bdb9002d84"
};
firebase.initializeApp(firebaseConfig)

new Vue({
  render: h => h(App),
  Bootstrap,
}).$mount('#app')
