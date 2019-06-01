<template>
  <div @click="" class="control-card col-4 p-1">
    <div :class="['row wrapper', {'isOff': offClass}]">
      <div class="col-3 pic">
        <img v-if="isOn" class="student-pic" :src="image" alt="">
        <img v-if="!isOn" class="student-pic" :src="imagee" alt="">
      </div>
      <div class="col-9 center">
        <p>
          {{ name }} 
          <b v-if="!offClass"> <br> is doing fine</b>
          <b v-else>need help</b>
        </p>
      </div>
    </div>
  </div>
</template>

<script>
import { database } from 'firebase'
export default {
  name: 'ControlCard',
  props: ['name', 'path', 'image', 'imagee'],
  data () {
    return {
      isOn: null
    }
  },
  mounted () {
    let data = database().ref(this.path)
    let self = this
    data.on('value', function(snapshot) {
      self.isOn = snapshot.val()
    })
  },
  methods: {
    push () {
      console.log('Push!')
      if (this.isOn == true) {
        database().ref(this.path).set(false)
      } else {
        database().ref(this.path).set(true)
      }
    }
  },
  computed: {
    offClass () {
      if (this.isOn) return false
      else return true
    }
  }
}
</script>

<style lang="scss" scoped>
.control-card {
  margin-left: 0%;
  .wrapper {
    padding: 10px 3px;
    background: rgb(137, 255, 176);
    margin: 1px;
    border-radius: 12px;
  }
  p {
    margin-bottom: 0;
  }
}
.center {
  display: flex;
  justify-content: center;
  align-items: center;
}
.isOff {
  background: #ff1616!important;
  color: #fff;
  animation: test 1s infinite;
  opacity: 0.8;
}
.pic {
  padding: 0;
}
.student-pic {
  width: 50px;
}
@-webkit-keyframes test {
  0%   { opacity: 0.3; }
  100% { opacity: 0.9; }
}
</style>

