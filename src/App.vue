<template>
  <div id="app">
    <audio id="audio1"><source :src="require('./assets/1.mp3')" type="audio/mpeg"></audio>
    <audio id="audio2"><source :src="require('./assets/2.mp3')" type="audio/mpeg"></audio>
    <audio id="audio3"><source :src="require('./assets/3.mp3')" type="audio/mpeg"></audio>
    <audio id="audio4"><source :src="require('./assets/4.mp3')" type="audio/mpeg"></audio>
    <audio id="audio5"><source :src="require('./assets/5.mp3')" type="audio/mpeg"></audio>
    <audio id="audio6"><source :src="require('./assets/6.mp3')" type="audio/mpeg"></audio>
    <audio id="audio7"><source :src="require('./assets/7.mp3')" type="audio/mpeg"></audio>
    <audio id="audio8"><source :src="require('./assets/555.mp3')" type="audio/mpeg"></audio>
    <audio id="audio9"><source :src="require('./assets/9.mp3')" type="audio/mpeg"></audio>
    
    <div id="realheader">
      <div class="row realrow">
        <div class="col">
          <img src="./assets/111.png" alt="" class="header">
        </div>
        
      </div>
    </div>
    
    
    <div class="container">      
      <div class="bot">
        <div class="row">
        <div class="col">
          <hr>
        </div>
      </div>
       <div class="row">
       <div class="col-6 test">      
          <div v-for="item in arr" v-bind:key="item">
           <reciever :num="item"/>
          </div>
       </div>
       <div class="col-6">
        <div class="row">

          <!--กล่องแสดงข้อมูล-->  
          <data-card name="Just fine" path="fine"/>
          <data-card name="Score" path="score/1"/>
          <data-card name="Need help" path="help"/>
          <!--กล่องแสดงข้อมูล-->

        </div>

        <div class="row">

          <!--กล่องปุ่มควบคุม-->

          <control-card name="student 1" path="student/1" :image="require('./assets/student.png')" :imagee="require('./assets/student2.png')"/>
          <control-card name="student 2" path="student/2" :image="require('./assets/student.png')" :imagee="require('./assets/student2.png')"/>
          <control-card name="student 3" path="student/3" :image="require('./assets/student.png')" :imagee="require('./assets/student2.png')"/>
          <control-card name="student 4" path="student/4" :image="require('./assets/student.png')" :imagee="require('./assets/student2.png')"/>
          <control-card name="student 5" path="student/5" :image="require('./assets/student.png')" :imagee="require('./assets/student2.png')"/>
          <control-card name="student 6" path="student/6" :image="require('./assets/student.png')" :imagee="require('./assets/student2.png')"/>
          <control-card name="student 7" path="student/7" :image="require('./assets/student.png')" :imagee="require('./assets/student2.png')"/>
          <control-card name="student 8" path="student/8" :image="require('./assets/student.png')" :imagee="require('./assets/student2.png')"/>
          <control-card name="student 9" path="student/9" :image="require('./assets/student.png')" :imagee="require('./assets/student2.png')"/>
          <control-card name="student 10" path="student/10" :image="require('./assets/student.png')" :imagee="require('./assets/student2.png')"/>
          <control-card name="student 11" path="student/11" :image="require('./assets/student.png')" :imagee="require('./assets/student2.png')"/>
          <control-card name="student 12" path="student/12" :image="require('./assets/student.png')" :imagee="require('./assets/student2.png')"/>
          <control-card name="student 13" path="student/13" :image="require('./assets/student.png')" :imagee="require('./assets/student2.png')"/>
          <control-card name="student 14" path="student/14" :image="require('./assets/student.png')" :imagee="require('./assets/student2.png')"/>
          <control-card name="student 15" path="student/15" :image="require('./assets/student.png')" :imagee="require('./assets/student2.png')"/>
          <control-card name="student 16" path="student/16" :image="require('./assets/student.png')" :imagee="require('./assets/student2.png')"/>
          <control-card name="student 17" path="student/17" :image="require('./assets/student.png')" :imagee="require('./assets/student2.png')"/>
          <control-card name="student 18" path="student/18" :image="require('./assets/student.png')" :imagee="require('./assets/student2.png')"/>
          
          <!--กล่องปุ่มควบคุม-->
         
          
        </div>
        </div>
       </div>
      </div>
    </div>
    <div id="footer">
      <h6>Dumbell Mook Namphett Toey naja </h6>
    </div>
  </div>
</template>

<script>
import { database } from 'firebase'
import DataCard from '@/components/DataCard'
import ControlCard from '@/components/ControlCard'
import Reciever from '@/components/Reciever'
export default {
  name: 'app',
  components: {
    DataCard,
    ControlCard,
    Reciever
  },data () {
    return {
      message: "",
      arr: []
    }
  },
  mounted () {
    
    let data = database().ref("text")
    
    let self = this
    data.on('value', function(snapshot) {
      let msg = snapshot.val()
      msg = Object.values(msg)
      self.play(msg.slice(-1)[0])
      self.arr =  Array.from(new Array(Math.min(msg.length, 11)), (x,i) => i)

    })
  },
  methods: {
    play: function (num) {
      var audio = document.getElementById(`audio${num}`)
      console.log(num)
      audio.play().catch(function(err) {
        console.log(err)
      });
    }
  }
  
  
}
</script>

<style lang="scss" scoped>
@import url('https://fonts.googleapis.com/css?family=Mitr&display=swap');
*{
  font-family: 'Mitr', sans-serif;
}

#footer {
  width: 100%;
  height: 50px;
  background-color: rgb(107, 88, 88);
  position: fixed;
  bottom: 0;
  color: #FFF;
  display: flex;
  justify-content: center;
  flex-direction: column;
}
.colheader {
  margin: auto;
}
#realheader {
  
  background-color: rgb(107, 88, 88);
  display: flex;
  align-items: center;
  flex-direction: column;
}
.realrow {
  width: 65vh;
}
.header{
   height: 15vh;
}
.bot{
  margin-top: 20px;
}
.nav img{
   height: 15vh;            
  }
.test{
  display: flex;
  align-items: center;
  flex-direction: column;
  // background: url('./assets/phone1.png');
  background-size: cover;
}
#app {
  font-family: 'Avenir', Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
  margin: 3vh 0;
}
</style>
